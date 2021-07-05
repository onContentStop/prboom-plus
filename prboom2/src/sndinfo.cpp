#include "sndinfo.h"

#include <tao/pegtl.hpp>
#include <tao/pegtl/ascii.hpp>
#include <tao/pegtl/contrib/analyze.hpp>

#include "w_wad.h"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace sndinfo {

struct lump_name : pegtl::rep_max<8, pegtl::alnum> {};
struct sound_name : pegtl::plus<pegtl::sor<pegtl::alnum, pegtl::one<'/'>>> {};

struct random_decl
    : pegtl::seq<pegtl::string<'$', 'r', 'a', 'n', 'd', 'o', 'm'>,
                 pegtl::plus<pegtl::space>, sound_name,
                 pegtl::star<pegtl::space>, pegtl::one<'{'>,
                 pegtl::star<pegtl::space>,
                 pegtl::plus<pegtl::seq<sound_name, pegtl::plus<pegtl::space>>,
                             pegtl::one<'}'>>> {};

struct sound_decl
    : pegtl::seq<sound_name, pegtl::plus<pegtl::space>, lump_name> {};

struct alias_decl : pegtl::seq<pegtl::string<'$', 'a', 'l', 'i', 'a', 's'>,
                               pegtl::plus<pegtl::space>, sound_name,
                               pegtl::plus<pegtl::space>, sound_name> {};

struct file
    : pegtl::star<pegtl::seq<pegtl::sor<random_decl, sound_decl, alias_decl>,
                             pegtl::plus<pegtl::space>>> {};

struct parsed_decl {};

struct parsed_random_decl : public parsed_decl {
  std::string name;
  std::vector<std::string> elements;
};

template <typename Rule>
struct action : pegtl::nothing<Rule> {};

template <>
struct action<random_decl> {
  template <typename ActionInput>
  static void apply(const ActionInput& in,
                    std::vector<std::unique_ptr<parsed_decl>>& out) {}
};

}  // namespace sndinfo

void parse_sndinfo() {
  const char* lump = static_cast<const char*>(W_CacheLumpName("SNDINFO"));
  if (lump == nullptr) {
    return;
  }

  if (pegtl::analyze<sndinfo::file>() != 0) {
    fprintf(stderr,
            "[\x1b[1;31mFTL\x1b[0m] FATAL ERROR: analysis of SNDINFO grammar "
            "failed!\n");
    exit(1);
  }
}
