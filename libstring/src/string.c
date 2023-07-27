#include "lstring.h"

size_t str_length(string str)
{
    size_t length = 0;

    if (str == NULL)
        return (0);
    while (str[++length] != '\0');
    return (length);
}

bool str_is_empty(string str)
{
    if (str == NULL || str[0] == '\0')
        return (true);
    return (false);
}

bool str_is_blank(string str)
{
    bool isBlank = true;

    if (str == NULL)
        return (true);

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > 32 && str[i] < 127)
            isBlank = false;
    return (isBlank);
}

bool str_starts_with(string str, string start)
{
    if (str == NULL || start == NULL)
        return (false);

    if (str_length(str) < str_length(start))
        return (false);

    for (size_t i = 0; start[i] != '\0'; i++)
        if (start[i] != str[i])
            return (false);

    return (true);
}

bool str_ends_with(string str, string end)
{
    if (str == NULL || end == NULL)
        return (false);

    size_t strIndex = str_length(str) - 1;
    size_t endIndex = str_length(end) - 1;

    if (strIndex < endIndex)
        return (false);
    
    for (size_t i = 0; i <= endIndex; i++) {
        if (str[strIndex - i] != end[endIndex - i])
            return (false);
    }

    return (true);
}