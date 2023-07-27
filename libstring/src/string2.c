#include "lstring.h"
#include <stdio.h>

bool str_contains(string src, string search)
{
    if (src == NULL || search == NULL)
        return (false);

    size_t src_len = str_length(src);
    size_t search_len = str_length(search);
    bool contains = false;

    if (src_len < search_len || src_len == 0 || search_len == 0)
        return (false);

    for (size_t i = 0; src_len - i >= search_len; i++) {
        if (search[0] == src[i]) {
            contains = true;
            for (size_t j = 0; search[j] != '\0'; j++) {
                if (search[j] != src[i + j]) {
                    contains = false;
                    break;
                }
            }
            if (contains == true)
                return (true);
        }
    }

    return (contains);
}

bool str_equals(string firstStr, string secondStr)
{
    size_t firstStrLength = str_length(firstStr);
    size_t secondStrLength = str_length(secondStr);

    if (firstStr == NULL || secondStr == NULL || firstStrLength != secondStrLength)
        return (false);
    for (size_t i = 0; i < firstStrLength; i++) {
        if (firstStr[i] != secondStr[i])
            return (false);
    }
    return (true);
}

bool str_compare_mult(string str, ...)
{
    va_list list;

    if (str == NULL)
        return (false);

    va_start(list, str);
    string choice;

    while ((choice = va_arg(list, string)) != NULL)
        if (str_equals(str, choice))
            return (true);
    return (false);
}

int str_compare_array(string str, string *array)
{
    if (str == NULL || array == NULL)
        return (-1);
    
    for (size_t i = 0; array[i] != NULL; i++)
        if (str_equals(str, array[i]))
            return (i);

    return (0);
}