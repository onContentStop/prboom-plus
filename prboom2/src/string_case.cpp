//
// Created by kyle2 on 7/11/21.
//

#include "string_case.h"

#include <cstring>
#include <rest_my_case.hpp>

static MyWords ucwds{};
static MyWords lcwds{"a",  "an", "the", "at",  "by", "for", "in",
                     "of", "on", "to",  "and", "as", "or"};
static MyTitleCase myTitleCase{&lcwds, &ucwds};
static MyTrainCase myTrainCase{&lcwds, &ucwds};
static MyStartCase myStartCase{&lcwds, &ucwds};
static MySnakeCase mySnakeCase{&lcwds, &ucwds};
static MyCamelCase myCamelCase{&lcwds, &ucwds};
static MyCamelBack myCamelBack{&lcwds, &ucwds};
static MyUpperCase myUpperCase{&lcwds, &ucwds};
static MyLowerCase myLowerCase{&lcwds, &ucwds};

char* strToC(std::string_view str) {
  char* c = static_cast<char*>(malloc(str.size() + 1));
  strncpy(c, str.data(), str.size());
  return c;
}

char* stringTitleCase(const char* str) {
  return strToC(MyTitleCase{}.myCase(str));
}
char* stringTrainCase(const char* str) {
  return strToC(MyTrainCase{}.myCase(str));
}
char* stringSnakeCase(const char* str) {
  return strToC(MySnakeCase{}.myCase(str));
}
char* stringCamelCase(const char* str) {
  return strToC(MyCamelCase{}.myCase(str));
}
char* stringCamelBack(const char* str) {
  return strToC(MyCamelBack{}.myCase(str));
}
char* stringUpperCase(const char* str) {
  return strToC(MyUpperCase{}.myCase(str));
}
char* stringLowerCase(const char* str) {
  return strToC(MyLowerCase{}.myCase(str));
}
char* stringStartCase(const char* str) {
  return strToC(MyStartCase{}.myCase(str));
}
namespace string {
std::string titleCase(std::string_view str) { return MyTitleCase{}.myCase(str); }
std::string trainCase(std::string_view str) { return MyTrainCase{}.myCase(str); }
std::string snakeCase(std::string_view str) { return MySnakeCase{}.myCase(str); }
std::string camelCase(std::string_view str) { return MyCamelCase{}.myCase(str); }
std::string camelBack(std::string_view str) { return MyCamelBack{}.myCase(str); }
std::string upperCase(std::string_view str) { return MyUpperCase{}.myCase(str); }
std::string lowerCase(std::string_view str) { return MyLowerCase{}.myCase(str); }
std::string startCase(std::string_view str) { return MyStartCase{}.myCase(str); }
}  // namespace string
