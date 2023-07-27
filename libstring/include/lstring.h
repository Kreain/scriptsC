#ifndef LSTRING_H_
#define LSTRING_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

typedef char* string;

size_t str_length(string str);
bool str_is_empty(string str);
bool str_is_blank(string str);
bool str_contains(string src, string search);
bool str_equals(string str, string str2);
bool str_starts_with(string str, string start);
bool str_ends_with(string str, string end);
bool str_compare_mult(string str, ...);
int str_compare_array(string str, string *array);

// int str_replace(string search, string replace);
// int string_append(string str, string toAppend);
// int string_append_mult(string str, ...);
// int str_to_lowercase(string str);
// int str_to_uppercase(string str);
// char str_char_at(size_t position);
// int str_replace_char_at(size_t position, char replace);

#endif /* LSTRING_H_ */