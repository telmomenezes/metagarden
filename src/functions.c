#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "config.h"
#include "str_utils.h"


int function_arity(int fun)
{
    if (fun >= FIRST_PRIVATE_WRITE) {
        return 1;
    }

    switch(fun) {
    case FUN_IF:
        return 3;
    case FUN_PLUS:
    case FUN_MINUS:
    case FUN_MULTIPLY:
    case FUN_DIVIDE:
    case FUN_MOD:
    case FUN_EQUAL:
    case FUN_GREATER:
    case FUN_LESSER:
    case FUN_GE:
    case FUN_LE:
    case FUN_AND:
    case FUN_OR:
    case FUN_SHL:
    case FUN_SHR:
    case FUN_BAND:
    case FUN_BOR:
    case FUN_BXOR:
    case FUN_BNOT:
        return 2;
    case FUN_NOT:
    case FUN_ABS:
    case FUN_NEG:
    case FUN_ODD:
    case FUN_EVEN:
        return 1;
    default:
        printf("Unknown function: %d", fun);
        return 0;
    }
}

char* function_to_str(int fun) {
    char *str;

    if (fun >= FIRST_PUBLIC_WRITE) {
        int reg = fun - FIRST_PUBLIC_WRITE;
        char *str_num = int_to_str(reg);
        size_t l = strlen(str_num) + 8;
        str = (char *)malloc(l);
        snprintf(str, l, "WRITE_#%s", str_num);
        free(str_num);
        return str;
    }
    if (fun >= FIRST_PRIVATE_WRITE) {
        int reg = fun - FIRST_PRIVATE_WRITE;
        char *str_num = int_to_str(reg);
        size_t l = strlen(str_num) + 8;
        str = (char *)malloc(l);
        snprintf(str, l, "WRITE_$%s", str_num);
        free(str_num);
        return str;
    }

    int l = 20;
    str = (char *)malloc(l);
    switch(fun) {
    case FUN_IF:
        snprintf(str, l, "%s", "if");
        break;
    case FUN_PLUS:
        snprintf(str, l, "%s", "+");
        break;
    case FUN_MINUS:
        snprintf(str, l, "%s", "-");
        break;
    case FUN_MULTIPLY:
        snprintf(str, l, "%s", "*");
        break;
    case FUN_DIVIDE:
        snprintf(str, l, "%s", "/");
        break;
    case FUN_MOD:
        snprintf(str, l, "%s", "%%");
        break;
    case FUN_ABS:
        snprintf(str, l, "%s", "abs");
        break;
    case FUN_NEG:
        snprintf(str, l, "%s", "neg");
        break;
    case FUN_EQUAL:
        snprintf(str, l, "%s", "=");
        break;
    case FUN_GREATER:
        snprintf(str, l, "%s", ">");
        break;
    case FUN_LESSER:
        snprintf(str, l, "%s", "<");
        break;
    case FUN_GE:
        snprintf(str, l, "%s", ">=");
        break;
    case FUN_LE:
        snprintf(str, l, "%s", "<=");
        break;
    case FUN_AND:
        snprintf(str, l, "%s", "and");
        break;
    case FUN_OR:
        snprintf(str, l, "%s", "or");
        break;
    case FUN_NOT:
        snprintf(str, l, "%s", "not");
        break;
    case FUN_ODD:
        snprintf(str, l, "%s", "odd");
        break;
    case FUN_EVEN:
        snprintf(str, l, "%s", "even");
        break;
    case FUN_SHL:
        snprintf(str, l, "%s", "<<");
        break;
    case FUN_SHR:
        snprintf(str, l, "%s", ">>");
        break;
    case FUN_BAND:
        snprintf(str, l, "%s", "&");
        break;
    case FUN_BOR:
        snprintf(str, l, "%s", "|");
        break;
    case FUN_BXOR:
        snprintf(str, l, "%s", "^");
        break;
    case FUN_BNOT:
        snprintf(str, l, "%s", "!");
        break;
    default:
        snprintf(str, l, "%s", "???");
    }

    return str;
}
