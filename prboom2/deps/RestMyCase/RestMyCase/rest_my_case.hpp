//
// Created by kyle2 on 7/11/21.
//

#ifndef VEC_REST_MY_CASE_HPP
#define VEC_REST_MY_CASE_HPP

// Your name: Jft
// Your email:

// V3.8

#include <algorithm>
#include <array>
#include <cctype>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// Is Exec Policy supported
#if defined(_MSC_VER) && defined(_HAS_CXX17)
#include <execution>

#define EXECPOLICY std::execution::seq
//#define EXECPOLICY std::execution::par
//#define EXECPOLICY std::execution::par_unseq
#endif

// Cuts down on the typing!!
#define NODISC [[nodiscard]]
#define UNUSED [[maybe_unused]]

struct isa {
  bool isapunct = false;
  bool isaspace = false;
  bool isaupper = false;
  bool isalower = false;
  bool isadigit = false;
};

constexpr std::array<isa, std::numeric_limits<std::uint8_t>::max() + 1> chars{
    isa{false, false, false, false, false},  //   0   0 NUL
    {false, false, false, false, false},     //   1   1 SCH ^A
    {false, false, false, false, false},     //   2   2 STX ^B
    {false, false, false, false, false},     //   3   3 ETX ^C
    {false, false, false, false, false},     //   4   4 BOT ^D
    {false, false, false, false, false},     //   5   5 ENQ ^E
    {false, false, false, false, false},     //   6   6 ACK ^F
    {false, false, false, false, false},     //   7   7 BEL ^G
    {false, false, false, false, false},     //   8   8 BS  ^H
    {false, true, false, false, false},      //   9   9 HT  ^I
    {false, true, false, false, false},      //  10  0a LF  ^J
    {false, true, false, false, false},      //  11  0b VT  ^K
    {false, true, false, false, false},      //  12  0c FF  ^L
    {false, true, false, false, false},      //  13  0d CR  ^M
    {false, false, false, false, false},     //  14  0e SO  ^N
    {false, false, false, false, false},     //  15  0f SI  ^O
    {false, false, false, false, false},     //  16  10 DLE ^P
    {false, false, false, false, false},     //  17  11 DC1 ^Q
    {false, false, false, false, false},     //  18  12 DC2 ^R
    {false, false, false, false, false},     //  19  13 DC3 ^S
    {false, false, false, false, false},     //  20  14 DC4 ^T
    {false, false, false, false, false},     //  21  15 NAK ^U
    {false, false, false, false, false},     //  22  16 SYN ^V
    {false, false, false, false, false},     //  23  17 ETB ^W
    {false, false, false, false, false},     //  24  18 CAN ^X
    {false, false, false, false, false},     //  25  19 EM  ^Y
    {false, false, false, false, false},     //  26  1a SCB ^Z
    {false, false, false, false, false},     //  27  1b ESC
    {false, false, false, false, false},     //  28  1c FS
    {false, false, false, false, false},     //  29  1d GS
    {false, false, false, false, false},     //  30  1e RS
    {false, false, false, false, false},     //  31  1f OS
    {false, true, false, false, false},      //  32  20 <SPACE>
    {true, false, false, false, false},      //  33  21 !
    {true, false, false, false, false},      //  34  22 "
    {true, false, false, false, false},      //  35  23 #
    {true, false, false, false, false},      //  36  24 $
    {true, false, false, false, false},      //  37  25 %
    {true, false, false, false, false},      //  38  26 &
    {true, false, false, false, false},      //  39  27 '
    {true, false, false, false, false},      //  40  28 (
    {true, false, false, false, false},      //  41  29 }
    {true, false, false, false, false},      //  42  2a *
    {true, false, false, false, false},      //  43  2b +
    {true, false, false, false, false},      //  44  2c ,
    {true, false, false, false, false},      //  45  2d -
    {true, false, false, false, false},      //  46  2e .
    {true, false, false, false, false},      //  47  2f /
    {false, false, false, false, true},      //  48  30 0
    {false, false, false, false, true},      //  49  31 1
    {false, false, false, false, true},      //  50  32 2
    {false, false, false, false, true},      //  51  33 3
    {false, false, false, false, true},      //  52  34 4
    {false, false, false, false, true},      //  53  35 5
    {false, false, false, false, true},      //  54  36 6
    {false, false, false, false, true},      //  55  37 7
    {false, false, false, false, true},      //  56  38 8
    {false, false, false, false, true},      //  57  39 9
    {true, false, false, false, false},      //  58  3a :
    {true, false, false, false, false},      //  59  3b ;
    {true, false, false, false, false},      //  60  3c <
    {true, false, false, false, false},      //  61  3d =
    {true, false, false, false, false},      //  62  3e >
    {true, false, false, false, false},      //  63  3f ?
    {true, false, false, false, false},      //  64  40 @
    {false, false, true, false, false},      //  65  41 A
    {false, false, true, false, false},      //  66  42 B
    {false, false, true, false, false},      //  67  43 C
    {false, false, true, false, false},      //  68  44 D
    {false, false, true, false, false},      //  69  45 E
    {false, false, true, false, false},      //  70  46 F
    {false, false, true, false, false},      //  71  47 G
    {false, false, true, false, false},      //  72  48 H
    {false, false, true, false, false},      //  73  49 I
    {false, false, true, false, false},      //  74  4a J
    {false, false, true, false, false},      //  75  4b K
    {false, false, true, false, false},      //  76  4c L
    {false, false, true, false, false},      //  77  4d M
    {false, false, true, false, false},      //  78  4e N
    {false, false, true, false, false},      //  79  4f O
    {false, false, true, false, false},      //  80  50 P
    {false, false, true, false, false},      //  81  51 Q
    {false, false, true, false, false},      //  82  52 R
    {false, false, true, false, false},      //  83  53 S
    {false, false, true, false, false},      //  84  54 T
    {false, false, true, false, false},      //  85  55 U
    {false, false, true, false, false},      //  86  56 V
    {false, false, true, false, false},      //  87  57 W
    {false, false, true, false, false},      //  88  58 X
    {false, false, true, false, false},      //  89  59 Y
    {false, false, true, false, false},      //  90  5a Z
    {true, false, false, false, false},      //  91  5b [
    {true, false, false, false, false},      //  92  5c \ //
    {true, false, false, false, false},      //  93  5d ]
    {true, false, false, false, false},      //  94  5e ^
    {true, false, false, false, false},      //  95  5f _
    {true, false, false, false, false},      //  96  60 `
    {false, false, false, true, false},      //  97  61 a
    {false, false, false, true, false},      //  98  62 b
    {false, false, false, true, false},      //  99  63 c
    {false, false, false, true, false},      // 100  64 d
    {false, false, false, true, false},      // 101  65 e
    {false, false, false, true, false},      // 102  66 f
    {false, false, false, true, false},      // 103  67 g
    {false, false, false, true, false},      // 104  68 h
    {false, false, false, true, false},      // 105  69 i
    {false, false, false, true, false},      // 106  6a j
    {false, false, false, true, false},      // 107  6b k
    {false, false, false, true, false},      // 108  6c l
    {false, false, false, true, false},      // 109  6d m
    {false, false, false, true, false},      // 110  6e n
    {false, false, false, true, false},      // 111  6f o
    {false, false, false, true, false},      // 112  70 p
    {false, false, false, true, false},      // 113  71 q
    {false, false, false, true, false},      // 114  72 r
    {false, false, false, true, false},      // 115  73 s
    {false, false, false, true, false},      // 116  74 t
    {false, false, false, true, false},      // 117  75 u
    {false, false, false, true, false},      // 118  76 v
    {false, false, false, true, false},      // 119  77 w
    {false, false, false, true, false},      // 120  78 x
    {false, false, false, true, false},      // 121  79 y
    {false, false, false, true, false},      // 122  7a z
    {true, false, false, false, false},      // 123  7b {
    {true, false, false, false, false},      // 124  7c :
    {true, false, false, false, false},      // 125  7d }
    {true, false, false, false, false},      // 126  7e ~
    {false, false, false, false, false}      // 127  7f DEL
};

// string_view is read only class but this simple cut-down version allows
// read/write to the underlying memory! Used by token structure to refer to
// parts of input line string for in-situ change
class StrAmd {
 public:
  // No dynamic memory so defaults ok
  StrAmd() = default;
  StrAmd(const StrAmd&) = default;
  StrAmd(StrAmd&&) = default;
  StrAmd& operator=(const StrAmd&) = default;
  StrAmd& operator=(StrAmd&&) = default;
  ~StrAmd() = default;

  // Constructors from start/end pointers and std::string
  constexpr StrAmd(const uint8_t* st, const uint8_t* ed)
      : str(const_cast<uint8_t*>(st)), send(const_cast<uint8_t*>(ed)) {}
  StrAmd(const std::string& st)
      : str(reinterpret_cast<uint8_t*>(const_cast<char*>(st.data()))),
        send(reinterpret_cast<uint8_t*>(
            const_cast<char*>((st.data() + st.size())))) {}

  NODISC constexpr auto begin() const noexcept { return str; }
  NODISC constexpr auto end() const noexcept { return send; }
  NODISC constexpr size_t size() const noexcept {
    return static_cast<size_t>(send - str);
  }
  NODISC constexpr uint8_t& front() { return *str; }
  NODISC constexpr uint8_t& back() { return *(send - 1); }
  NODISC constexpr bool empty() const noexcept { return str == send; }
  constexpr void clear() noexcept { str = send = nullptr; }

  // This compares the contents, not the pointers
  constexpr inline bool operator!=(StrAmd rhs) const noexcept;

  // Conversion function std::string_view from StrAmd
  // operator std::string() const { return std::string(str, send); }
  operator std::string_view() const noexcept {
    return std::string_view(reinterpret_cast<char*>(str), send - str);
  }

  // Stream insertion for test purposes
  friend inline std::ostream& operator<<(std::ostream& os, StrAmd sv);

 private:
  uint8_t* str = nullptr;   // String start
  uint8_t* send = nullptr;  // String end
};

// Class to deal with words
class MyWords {
 public:
  // Word processing static functions
  NODISC inline static bool isCaps(StrAmd w) noexcept;  // Is word all caps
  inline static void toLc(StrAmd w) noexcept;           // Convert to all lc
  inline static void toUc(StrAmd w) noexcept;           // Convert to all uc
  /*constexpr*/ inline static void initial(
      StrAmd w) noexcept;  // Set initial char to uc

  constexpr static uint8_t chconv = 'a' - 'A';

  // Char processing static functions
  NODISC constexpr static inline bool isspace(uint8_t ch) noexcept {
    return chars[ch].isaspace;
  }
  NODISC constexpr static inline bool ispunct(uint8_t ch) noexcept {
    return chars[ch].isapunct;
  }
  NODISC constexpr static inline bool isupper(uint8_t ch) noexcept {
    return chars[ch].isaupper;
  }
  NODISC constexpr static inline bool islower(uint8_t ch) noexcept {
    return chars[ch].isalower;
  }
  NODISC constexpr static inline bool isdigit(uint8_t ch) noexcept {
    return chars[ch].isadigit;
  }
  NODISC constexpr static inline uint8_t toupper(uint8_t ch) noexcept {
    return chars[ch].isalower ? ch - chconv : ch;
  }
  NODISC constexpr static inline uint8_t tolower(uint8_t ch) noexcept {
    return chars[ch].isaupper ? ch + chconv : ch;
  }

  MyWords() = default;
  virtual ~MyWords() = default;
  MyWords(const MyWords&) = default;
  MyWords(MyWords&&) = default;
  MyWords& operator=(const MyWords&) = default;
  MyWords& operator=(MyWords&&) = default;

  // Add list of words
  MyWords(const std::initializer_list<std::string>& wd);

  virtual bool inline exists(StrAmd w) const noexcept {
    return words.count(static_cast<std::string>(w));
  }  // Does word exist in list
  virtual void inline clear() noexcept { words.clear(); }  // Clear word list

  // Add new word(s) - note stored as lc
  virtual inline bool addWd(std::string wd);
  virtual bool addWd(const std::initializer_list<std::string>& wds);

  // Show words
  virtual std::ostream& showWds(std::ostream& os) const noexcept;

  // Delete existing word(s)
  virtual inline bool remWd(std::string wd);
  virtual bool remWd(const std::initializer_list<std::string>& wds);

  // Load/save word lists
  virtual bool loadWds(const std::string& lcfn);
  virtual bool saveWds(const std::string& lcfn) const noexcept;

 protected:
  // Using unordered set as find is quicker than ordered set.
  using SetStr = std::unordered_set<std::string>;
  // using SetStr = std::set<std::string>;

 private:
  SetStr words;  // Set of words
};

using Opts = uint16_t;  // 16 bits for options

// Main class. This provides all the interface functions
template <Opts OPTS, uint8_t SEPAR, typename WRDS = MyWords>
class RestMyCase {
 public:
  // No dynamic memory so defaults OK
  RestMyCase() = default;
  RestMyCase(const RestMyCase&) = default;
  RestMyCase(RestMyCase&&) = default;
  RestMyCase& operator=(const RestMyCase&) = default;
  RestMyCase& operator=(RestMyCase&&) = default;
  virtual ~RestMyCase() = default;

  // Constructor just sets pointer for the lc and uc words class
  constexpr RestMyCase(const WRDS* const lc, const WRDS* const uc)
      : lcwds(lc), ucwds(uc) {}

  // Main processing methods
  NODISC virtual inline std::string myCase(
      std::string_view ln);  // Line specified

  // Get/Set sentence termination punctuation
  virtual inline void setTermPunc(std::string_view punc) { sentend = punc; }
  NODISC virtual inline std::string getTermPunc() const noexcept {
    return sentend;
  }

 private:
  std::string line;                   // Line to convert
  std::string sentend = "!?.";        // These punctuations mark end of sentence
  const WRDS* const lcwds = nullptr;  // Pointer to class for lc words
  const WRDS* const ucwds = nullptr;  // Pointer to class for uc words

  // Structure for a word token
  struct Token {
    StrAmd word;      // Word
    StrAmd prefix;    // Prefix punctuation
    StrAmd suffix;    // Suffix punctuation
    size_t pos = 0U;  // Word position in sentence so parallel processing knows
                      // which word
    const RestMyCase* const myThis =
        nullptr;  // This pointer (so can access member variables from static)

    Token() = delete;  // No default constructor as needs this pointer
    Token(StrAmd w, StrAmd p, StrAmd s, size_t po, const RestMyCase* const th)
        : word(w), prefix(p), suffix(s), pos(po), myThis(th) {}
  };

  // Helper functions
  inline void newpos(UNUSED StrAmd st, UNUSED size_t& po)
      const noexcept;  // Determine if next word is start of sentence
  void procfix(UNUSED std::string& stcat, UNUSED StrAmd& prev,
               UNUSED StrAmd
                   fix) const noexcept;  // Process prefix/suffix punctuation

 protected:
  using TokCont = std::vector<Token>;

  NODISC virtual TokCont split() const;      // Split input line into tokens
  static void process(Token& tkn) noexcept;  // Process each token in parallel.
                                             // Needs static for parallel
  NODISC virtual std::string make(
      const TokCont& tkns) const;  // Make required case string

 public:
  // Options
  // Bits 0 - 7 used by base engine
  // Bits 8 - 15 available for use
  constexpr static Opts IgPun = 0b000000001;  // Ignore punctuation
  constexpr static Opts NoDup =
      0b000000010;  // Remove duplicate punctuation if IgPun not set
  constexpr static Opts MkCaps = 0b000000100;  // Make all words upper case
  constexpr static Opts IgCaps =
      0b000001000;  // Ignore words which are all upper case - leave as upper
                    // case
  constexpr static Opts ChkCaps =
      0b000010000;  // Make word upper case if word in ucwds
  constexpr static Opts FstCaps =
      0b000100000;  // First word always initial letter upper case (overrides
                    // MkLc)
  constexpr static Opts InitCaps =
      0b001000000;  // Initial letter of words (except first) upper case
  constexpr static Opts MkLc =
      0b010000000;  // Make lower case if word in lcwds (overrides InitCaps)

  // Required combination of options for different case types
  constexpr static Opts TitleCase =
      IgCaps | FstCaps | InitCaps | MkLc | ChkCaps | NoDup;
  constexpr static Opts TrainCase = IgPun | InitCaps;
  constexpr static Opts SnakeCase = IgPun;
  constexpr static Opts CamelCase = FstCaps | InitCaps | IgPun;
  constexpr static Opts CamelBack = InitCaps | IgPun;
  constexpr static Opts UpperCase = MkCaps | NoDup;
  constexpr static Opts LowerCase = NoDup;
  constexpr static Opts StartCase = FstCaps | InitCaps | NoDup;
};

// Predefined classes
// Note as TitleCase etc are defined as part of the class, they have to be
// referenced via a class instance
using DummyCase =
    RestMyCase<0, 0, MyWords>;  // For option reference via a dummy class

using MyTitleCase = RestMyCase<DummyCase::TitleCase, ' ', MyWords>;
using MyTrainCase = RestMyCase<DummyCase::TrainCase, '_', MyWords>;
using MySnakeCase = RestMyCase<DummyCase::SnakeCase, '_', MyWords>;
using MyCamelCase = RestMyCase<DummyCase::CamelCase, 0, MyWords>;
using MyCamelBack = RestMyCase<DummyCase::CamelBack, 0, MyWords>;
using MyUpperCase = RestMyCase<DummyCase::UpperCase, ' ', MyWords>;
using MyLowerCase = RestMyCase<DummyCase::LowerCase, ' ', MyWords>;
using MyStartCase = RestMyCase<DummyCase::StartCase, ' ', MyWords>;

// For testing, insertion of a StrAmd object into an output stream
inline std::ostream& operator<<(std::ostream& os, StrAmd sv) {
  return os << std::string_view(reinterpret_cast<char*>(sv.str),
                                sv.send - sv.str);
}

// Compares the contents pointed to by the strings
constexpr inline bool StrAmd::operator!=(StrAmd rhs) const noexcept {
  if ((rhs.send - rhs.str) != (send - str)) return true;

  for (auto c = str, r = rhs.str; c != send; ++c, ++r)
    if (*c != *r) return true;

  return false;
}

// Add list of words
MyWords::MyWords(const std::initializer_list<std::string>& wd) {
  for (const auto& w : wd) words.insert(w);
}

// Display words
// Note also used to save contents to file
inline std::ostream& MyWords::showWds(std::ostream& os) const noexcept {
  // words is an unordered set for performance reasons. So copy to vector and
  // sort before copy to output stream
  std::vector<std::string> vwds{words.begin(), words.end()};

#ifdef EXECPOLICY
  // Always do sort by parallel if execution policy supported
  std::sort(std::execution::par, vwds.begin(), vwds.end());
#else
  std::sort(vwds.begin(), vwds.end());
#endif

  std::copy(vwds.begin(), vwds.end(),
            std::ostream_iterator<std::string>(os, " "));
  return (os << std::endl);
}

// Add word
// Note wd pass by value as contents changed
inline bool MyWords::addWd(std::string wd) {
  toLc(wd);

  return words.insert(std::move(wd)).second;
}

// Add all specified words
bool MyWords::addWd(const std::initializer_list<std::string>& wds) {
  bool res = true;

  for (const auto& w : wds) res &= addWd(w);

  return res;
}

// Remove a word
// Note wd pass by value as contents changed
inline bool MyWords::remWd(std::string wd) {
  toLc(wd);

  return words.erase(std::move(wd));
}

// Remove all specified words
bool MyWords::remWd(const std::initializer_list<std::string>& wds) {
  bool res = true;

  for (const auto& w : wds) res &= remWd(w);

  return res;
}

// Load word list
// Return true if successful
bool MyWords::loadWds(const std::string& fn) {
  std::ifstream ifs(fn);

  if (!ifs.is_open()) return false;

  words.clear();

  std::string wd;

  // Slow way of doing it but performance not an issue here
  while (ifs >> wd) {
    toLc(wd);
    words.insert(std::move(wd));
  }

  ifs.close();
  return !words.empty();
}

// Save word list
// Return true if successful
bool MyWords::saveWds(const std::string& fn) const noexcept {
  std::ofstream ofs(fn);

  if (!ofs.is_open()) return false;

  bool ret = !!showWds(ofs);

  ofs.close();
  return ret;
}

// Check if a word is all caps
// Return true if all caps
NODISC inline bool MyWords::isCaps(StrAmd w) noexcept {
#ifdef EXECPOLICY
  return std::all_of(EXECPOLICY, w.begin(), w.end(),
                     [](auto ch) { return MyWords::isupper(ch); });
  // return std::all_of(EXECPOLICY, w.begin(), w.end(), [](auto ch) {return
  // std::isupper(ch); });
#else
  return std::all_of(w.begin(), w.end(),
                     [](auto ch) { return MyWords::isupper(ch); });
// return std::all_of(w.begin(), w.end(), [](auto ch) {return std::isupper(ch);
// });
#endif
}

// Convert word w to lc
inline void MyWords::toLc(StrAmd w) noexcept {
#ifdef EXECPOLICY
  std::transform(EXECPOLICY, w.begin(), w.end(), w.begin(),
                 [](auto ch) { return MyWords::tolower(ch); });
  // std::transform(EXECPOLICY, w.begin(), w.end(), w.begin(), [](auto ch)
  // {return static_cast<uint8_t>(std::tolower(ch)); });
#else
  std::transform(w.begin(), w.end(), w.begin(),
                 [](auto ch) { return MyWords::tolower(ch); });
// std::transform(w.begin(), w.end(), w.begin(), [](auto ch) {return
// static_cast<uint8_t>(std::tolower(ch)); });
#endif
}

// Convert word w to uc
inline void MyWords::toUc(StrAmd w) noexcept {
#ifdef EXECPOLICY
  std::transform(EXECPOLICY, w.begin(), w.end(), w.begin(),
                 [](auto ch) { return MyWords::toupper(ch); });
  // std::transform(EXECPOLICY, w.begin(), w.end(), w.begin(), [](auto ch)
  // {return static_cast<uint8_t>(std::toupper(ch)); });
#else
  std::transform(w.begin(), w.end(), w.begin(),
                 [](auto ch) { return MyWords::toupper(ch); });
// std::transform(w.begin(), w.end(), w.begin(), [](auto ch) {return
// static_cast<uint8_t>(std::toupper(ch)); });
#endif
}

// Set initial letter uc
/*constexpr*/ inline void MyWords::initial(StrAmd w) noexcept {
  w.front() = MyWords::toupper(w.front());
  // w.front() = static_cast<uint8_t>(std::toupper(w.front()));
}

// Main processing function
// Returns converted text
template <Opts OPTS, uint8_t SEPAR, typename WRDS>
NODISC std::string RestMyCase<OPTS, SEPAR, WRDS>::myCase(std::string_view ln) {
  line = ln;  // Words will be converted in-situ

  // Split line into words and punctuation on white-space and ignore multi-white
  // space chars.
  auto tkns = split();

  // Process each word as per AS_PAR execution policy
#ifdef EXECPOLICY
  std::for_each(EXECPOLICY, tkns.begin(), tkns.end(), process);
#else
  std::for_each(tkns.begin(), tkns.end(), process);
#endif

  // Make required case string
  return make(tkns);
}

// Make() helper function
// Process prefix/suffix punctuation
template <Opts OPTS, uint8_t SEPAR, typename WRDS>
void RestMyCase<OPTS, SEPAR, WRDS>::procfix(UNUSED std::string& stcat,
                                            UNUSED StrAmd& prev,
                                            UNUSED StrAmd fix) const noexcept {
  // If punc to be discarded, do nothing!
  if constexpr (!(OPTS & IgPun)) {
    StrAmd st;

    // Duplicate consecutive punc check
    if constexpr ((OPTS & NoDup) > 0U)
      st = StrAmd(fix.begin(), std::unique(fix.begin(), fix.end()));
    else
      st = fix;

    // Deal with duplicate punctuation when originally separated
    if (!st.empty())
      if constexpr (!(OPTS & NoDup)) {
        prev = st;
        stcat += st;
      } else if (st != prev) {
        prev = st;
        stcat += st;
      }
  }
}

// Make required case string
template <Opts OPTS, uint8_t SEPAR, typename WRDS>
std::string RestMyCase<OPTS, SEPAR, WRDS>::make(const TokCont& tkns) const {
  std::string newlin;
  newlin.reserve(line.size());

  bool prevwd = false;  // Was there a word in the previous token
  StrAmd prev;          // Previous token

  // Create converted string
  // Cannot use a range-for as need to know if first element in tkns
  for (auto tkit = tkns.begin(); tkit != tkns.end(); ++tkit) {
    const auto& [word, prefix, suffix, pos, myThis] = *tkit;

    // Output separator at start of word unless first word and previous token
    // suffix only
    if (tkit != tkns.begin() && !word.empty() && prevwd) {
      if constexpr (SEPAR != 0) newlin += SEPAR;

      prev.clear();
    }

    // Output prefix punctuation if needed
    procfix(newlin, prev, prefix);

    // Output word
    newlin += word;

    // Is a separation needed on next word
    prevwd = !word.empty() || !suffix.empty();

    // Output suffix if needed
    procfix(newlin, prev, suffix);
  }

  // Resize new line as needed
  return newlin;
}

// Split() Helper function
// Determine if next word is start of sentence if suffix contains one of the
// sentence end chars
template <Opts OPTS, uint8_t SEPAR, typename WRDS>
inline void RestMyCase<OPTS, SEPAR, WRDS>::newpos(
    UNUSED StrAmd st, UNUSED size_t& po) const noexcept {
  if constexpr (!(OPTS & IgPun))
    if (std::find_first_of(st.begin(), st.end(), sentend.begin(),
                           sentend.end()) != st.end())
      po = 0U;
}

// Split string into vector of tokens on non-white and ignore multi non-white
// chars Deals with punctuation - including embedded and orphaned Returns
// vector<Token>
template <Opts OPTS, uint8_t SEPAR, typename WRDS>
NODISC typename RestMyCase<OPTS, SEPAR, WRDS>::TokCont
RestMyCase<OPTS, SEPAR, WRDS>::split() const {
  const auto fin =
      reinterpret_cast<uint8_t*>(const_cast<char*>(line.data() + line.size()));

  size_t pos = 0;  // Position in sentence.
  TokCont vsv;     // Vector of tokens

  vsv.reserve(1 + line.size() / 2);  // Assume worst case number of elements

  // Note used c -style casts below otherwise line far too long!
  for (auto st = (uint8_t*)line.data(), ed = (uint8_t*)line.data(),
            fst = (uint8_t*)line.data(), lst = (uint8_t*)line.data();
       st < fin; st = ed) {
    for (; (st < fin) && /*std*/ WRDS ::isspace(*st); ++st)
      ;  // Ignore leading spaces
    for (ed = st; (ed < fin) && !/*std*/ WRDS ::isspace(*ed); ++ed)
      ;  // Find end of word

    for (fst = st; (st < ed) && /*std*/ WRDS ::ispunct(*st); ++st)
      ;  // Skip leading punctuation
    for (lst = ed; (lst > st) && /*std*/ WRDS ::ispunct(*(lst - 1)); --lst)
      ;  // Skip trailing punctuation
    // Store data if word found
    if (st < lst) {
      // If punct in middle of word, split on punct with punct being suffix for
      // first
      auto pu = st, stp = st, lpu = st;

      for (; (pu < lst) && !/*std*/ WRDS ::ispunct(*pu); ++pu)
        ;  // Is there embedded punctuation

      if (pu < lst) {
        // Got embedded punctuation. May be more than one set so need to iterate
        while (pu < lst) {
          for (lpu = pu; /*std*/ WRDS ::ispunct(*lpu); ++lpu)
            ;  // Find end on punctuation
          const auto su = StrAmd(pu, lpu);

          vsv.emplace_back(StrAmd(stp, pu), StrAmd(), su, pos++,
                           this);  // Add word with suffix punctuation
          newpos(su, pos);

          for (stp = pu = lpu; (pu < lst) && !/*std*/ WRDS ::ispunct(*pu); ++pu)
            ;  // Find next punctuation if any
        }

        const auto su = StrAmd(lst, ed);

        vsv.emplace_back(StrAmd(stp, lst), StrAmd(), su, pos++,
                         this);  // Add end word with original suffix punc
        newpos(su, pos);
      } else {
        const auto su = StrAmd(lst, ed);

        vsv.emplace_back(StrAmd(st, lst), StrAmd(fst, st), su, pos++,
                         this);  // Add original word
        newpos(su, pos);
      }
    } else if (st < fin)
      // Got orphaned punctuation
      if (!vsv.empty()) {
        const auto su = StrAmd(fst, lst);

        vsv.emplace_back(StrAmd(), StrAmd(), su, pos,
                         this);  // If not first, add as suffix
        newpos(su, pos);
      } else
        vsv.emplace_back(StrAmd(), StrAmd(fst, lst), StrAmd(), pos,
                         this);  // First on line - add as prefix
  }

  return vsv;
}

// Process a word wd
// This is a parallel function and hence has to be static
// Non-static class access via myThis
template <Opts OPTS, uint8_t SEPAR, typename WRDS>
void RestMyCase<OPTS, SEPAR, WRDS>::process(Token& tkn) noexcept {
  auto& [word, pre, suf, pos, myThis] = tkn;

  // If no word
  if (word.empty()) return;

  // Ignore all CAPS words if required
  if constexpr ((OPTS & IgCaps) > 0U)
    if (WRDS::isCaps(word)) return;

  // If making all caps
  if constexpr ((OPTS & MkCaps) > 0U) {
    WRDS::toUc(word);
    return;
  }

  // Other options require word to all lower case first
  WRDS::toLc(word);

  // Check if word to be UC. Needs check here after toLc() as word to be checked
  // needs to be lc
  if constexpr ((OPTS & ChkCaps) > 0U)
    if (myThis->ucwds && myThis->ucwds->exists(word)) {
      WRDS::toUc(word);
      return;
    }

  // If first word and first initial needed then set
  if constexpr ((OPTS & FstCaps) > 0U)
    if (pos == 0) {
      WRDS::initial(word);
      return;
    }

  // If not first word, leave as lower case or initial caps as needed
  if (pos > 0) {
    if constexpr ((OPTS & MkLc) > 0U)
      if (myThis->lcwds && myThis->lcwds->exists(word)) return;

    if constexpr ((OPTS & InitCaps) > 0U) WRDS::initial(word);
  }
}

std::string simpleCase(const std::string& text) {
  std::stringstream result;
  bool newwrd = true;

  for (const auto ch : text) {
    newwrd |= (std::isspace(ch) != 0);
    if (std::isalpha(ch))
      if (newwrd) {
        result << static_cast<char>(std::toupper(ch));
        newwrd = false;
      } else
        result << static_cast<char>(std::tolower(ch));
    else
      result << ch;
  }

  return result.str();
}

#endif  // VEC_REST_MY_CASE_HPP
