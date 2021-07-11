//
// Created by kyle2 on 7/11/21.
//

#ifndef PRBOOM_PLUS_STRING_CASE_H
#define PRBOOM_PLUS_STRING_CASE_H

#ifdef __cplusplus
extern "C" {
#endif

char *stringTitleCase(const char *str);
char *stringTrainCase(const char *str);
char *stringSnakeCase(const char *str);
char *stringCamelCase(const char *str);
char *stringCamelBack(const char *str);
char *stringUpperCase(const char *str);
char *stringLowerCase(const char *str);
char *stringStartCase(const char *str);

#ifdef __cplusplus
}

#include <string>
#include <string_view>

char *strToC(std::string_view str);
namespace string {
std::string titleCase(std::string_view str);
std::string trainCase(std::string_view str);
std::string snakeCase(std::string_view str);
std::string camelCase(std::string_view str);
std::string camelBack(std::string_view str);
std::string upperCase(std::string_view str);
std::string lowerCase(std::string_view str);
std::string startCase(std::string_view str);
}  // namespace string
#endif

#endif  // PRBOOM_PLUS_STRING_CASE_H
