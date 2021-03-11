//
// Created by kyle on 3/11/21.
//

#include "d_think.hh"

std::ostream &operator<<(std::ostream &os, const thinker_t &thinker)
{
    return os << "thinker_t { next: " << thinker.next
              << ", prev: " << thinker.prev
              << ", function: " << thinker.function
              << ", cnext: " << thinker.cnext << ", cprev: " << thinker.cprev
              << ", references: " << thinker.references << " }";
}
