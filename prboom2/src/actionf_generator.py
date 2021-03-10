from enum import Enum, auto
import re
from subprocess import run


class State(Enum):
    start = auto()
    union = auto()
    types = auto()
    exp_variants = auto()
    variants = auto()


class Variant:
    def __init__(self, name, types):
        self.name = name
        self.types = types


class Fn:
    def __init__(self, ret, args):
        self.ret = ret
        self.args = args

    def p(self):
        return f"{self.ret} (*)({','.join(self.args)})"

    def __str__(self):
        return f"{self.ret} (*)({','.join(self.args)})"


if __name__ == "__main__":
    with open("unions.hh.in") as i:
        i_lines = i.readlines()

    state = State.start

    union_name = ""
    types = []
    variants = []
    line_num = 0

    try:
        with open("unions.hh", "w") as o:
            o.write("#pragma once\n")
            for line in i_lines:
                line = line.strip()
                line_num += 1
                if line == "":
                    continue

                line = list(
                    filter(
                        lambda w: w != "",
                        map(
                            lambda w: w.strip(), re.split(r"(\b|[,*()]|$)", line)[1:-1]
                        ),
                    )
                )
                print(line)

                if state == State.start:
                    if line[0] != "union":
                        raise ValueError(f"expected 'union', found '{line[0]}'")

                    union_name = line[1]
                    state = State.union

                elif state == State.union:
                    if line[0] != "types":
                        raise ValueError(f"expected 'types', found '{line[0]}'")
                    state = State.types
                elif state == State.types:
                    if line[0] == "types":
                        state = State.exp_variants
                        continue
                    o.write(f"struct {line[0]};\n")
                elif state == State.exp_variants:
                    if line[0] != "variants":
                        raise ValueError(f"expected 'variants', found '{line[0]}'")
                    state = State.variants
                elif state == State.variants:
                    if line[0] == "variants":
                        state = State.start

                        for ty in types:
                            o.write(f"struct {ty};")
                        o.write(f"class {union_name}{{")
                        o.write("public:")
                        for var in variants:
                            o.write(f"using t_{var.name} = ")
                            if isinstance(var.types, Fn):
                                o.write(var.types.p())
                            else:
                                o.write(var.types)
                            o.write(";")
                        o.write("private:")

                        for var in variants:
                            o.write(f"t_{var.name} m_{var.name} = nullptr;")

                        o.write("enum class discriminant {")
                        o.write("undefined,")
                        for var in variants:
                            o.write(f"{var.name},")
                        o.write("};")
                        o.write(
                            "discriminant m_discriminant = discriminant::undefined;"
                        )

                        o.write("public:")
                        o.write(f"constexpr {union_name}() = default;")
                        for var in variants:
                            o.write(f"constexpr {union_name}(")
                            o.write(f"t_{var.name} {var.name}")
                            o.write(")")
                            o.write(
                                f" : m_{var.name}({var.name}), m_discriminant(discriminant::{var.name}){{}}"
                            )

                            o.write(f"constexpr t_{var.name} {var.name}() {{")
                            o.write(f"return m_{var.name};")
                            o.write("}")

                        o.write(
                            f"constexpr bool operator==(const {union_name} &other) const {{"
                        )
                        o.write("switch (m_discriminant) {")
                        for var in variants:
                            o.write(f"case discriminant::{var.name}:")
                            o.write(f"return m_{var.name} == other.m_{var.name};")
                        o.write("case discriminant::undefined:")
                        o.write("return false;")
                        o.write("}")
                        o.write("}")
                        o.write(
                            f"constexpr bool operator!=(const {union_name} &other) const {{"
                        )
                        o.write("return !(*this == other);")
                        o.write("}")
                        o.write("};")
                        o.write(f"constexpr {union_name} {union_name.upper()}_NULL;")
                        types.clear()
                        variants.clear()
                        continue
                    var = Variant(line[0], [])
                    if line[1] != "(":
                        raise ValueError(f"expected '(', found '{line[1]}'")
                    start = i = 2
                    varg = []
                    farg = False

                    def finalize_arg():
                        if len(varg) == 0:
                            return
                        if farg and not isinstance(var.types, Fn):
                            var.types = Fn(varg[0], [" ".join(varg[1:])])
                        elif isinstance(var.types, Fn):
                            var.types.args.append(" ".join(varg))
                        else:
                            var.types = " ".join(varg)
                        varg.clear()

                    while line[i] != ")":
                        if line[i] == "fn":
                            farg = True
                        elif line[i] == ",":
                            finalize_arg()
                            start = i
                        else:
                            varg.append(line[i])
                        i += 1
                    finalize_arg()
                    print(f"name: {var.name}")
                    print(f"types: {var.types}")
                    variants.append(var)
        run(["clang-format", "-i", "unions.hh"])

    except ValueError as e:
        raise ValueError(f"bad file: line {line_num}: {e}")
