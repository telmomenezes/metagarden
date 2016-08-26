#ifndef STR_UTILS_H
#define STR_UTILS_H

#include <limits.h>


#define INT_CHARS ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)


char *int_to_str(int i);

#endif /* STR_UTILS_H */
