#include <stdlib.h>
#include <stdio.h>
#include "str_utils.h"


char *int_to_str(int i)
{
    char *str = (char *)malloc(INT_CHARS + 1);
    snprintf(str, INT_CHARS, "%d", i);
    return str;
}
