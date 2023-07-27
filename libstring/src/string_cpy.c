#include "lstring.h"

string str_copy(string str)
{
    string copied = malloc(str_length(str) + 1);

    size_t i = 0;
    for (; str[i] != '\0'; i++)
        copied[i] = str[i];
    copied[i] = '\0';

    return (copied);
}

string str_copy_to(string src, string dest)
{
    if (dest == NULL)
        return (NULL);
    
    size_t i = 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return (dest);
}