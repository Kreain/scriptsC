#include "lstring.h"

bool str_typeof_int(string str)
{
    size_t length;

    if (str == NULL || (length = str_length(str)) == 0)
        return (false);

    size_t i = 0;
    if (str[0] == '-')
        i++;
    for (; i < length; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}