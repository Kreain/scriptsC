#include "lstring.h"

#include <stdio.h>

int main(int ac, char **av) 
{
    string array[] = {"Hello", "World", "Test", NULL};

    for (int i = 0; i < 3; i++) {
        string str = array[i];
        printf("[%s]: %i\n", str, str_compare_array(str, array));
    }

    return (0);
}