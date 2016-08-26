#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define BASE_FUNS 24

#define FUN_IF 0
#define FUN_PLUS 1
#define FUN_MINUS 2
#define FUN_MULTIPLY 3
#define FUN_DIVIDE 4
#define FUN_MOD 5
#define FUN_ABS 6
#define FUN_NEG 7
#define FUN_EQUAL 8
#define FUN_GREATER 9
#define FUN_LESSER 10
#define FUN_GE 11
#define FUN_LE 12
#define FUN_AND 13
#define FUN_OR 14
#define FUN_NOT 15
#define FUN_ODD 16
#define FUN_EVEN 17
#define FUN_SHL 18
#define FUN_SHR 19
#define FUN_BAND 20
#define FUN_BOR 21
#define FUN_BXOR 22
#define FUN_BNOT 23

#define FUN_SPACING 1000
#define FIRST_PRIVATE_WRITE 1000
#define FIRST_PUBLIC_WRITE 2000


int function_arity();

char* function_to_str(int fun);

#endif /* FUNCTIONS_H */
