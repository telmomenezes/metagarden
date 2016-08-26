#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prog.h"
#include "node.h"
#include "rand.h"
#include "functions.h"
#include "config.h"
#include "str_utils.h"


unsigned int prog_size(struct node *prog)
{
    unsigned int total = 1;
    int i;
    for (i = 0; i < prog->child_count; i++) {
        total += prog_size((&prog->children)[i]);
    }
    return total;
}

struct node *prog_generate_random_var()
{
    int total = global_config->num_private_regs + global_config->num_public_regs;
    int choice = rand_uniform_max(total);
    struct node *var_node = (struct node *)malloc(sizeof(struct node));
    var_node->type = VAR_NODE;
    var_node->content = choice;
    var_node->child_count = 0;
    return var_node;
}

struct node *prog_generate_random_const()
{
    struct node *const_node = (struct node *)malloc(sizeof(struct node));
    const_node->type = CONST_NODE;
    const_node->content = rand_uniform();
    const_node->child_count = 0;
    return const_node;
}

struct node *prog_generate_random_fun(double terminator_prob, int max_depth, int depth)
{
    int num_private_regs = global_config->num_private_regs;
    int num_public_regs = global_config->num_public_regs;
    int num_funs = BASE_FUNS + num_private_regs + num_public_regs;

    int fun = rand_uniform_max(num_funs);
    if (fun >= BASE_FUNS) {
        fun -= BASE_FUNS;
        fun += FUN_SPACING;
    }
    if (fun >= num_private_regs + FUN_SPACING)
        fun += FUN_SPACING;

    int arity = function_arity(fun);

    int i;

    struct node *fun_node = (struct node *)malloc(sizeof(struct node));
    fun_node->type = FUN_NODE;
    fun_node->content = fun;
    fun_node->child_count = arity;
    fun_node->children = (struct node *)malloc(sizeof(struct node *) * arity);
    for (i = 0; i < arity; i++)
        (&fun_node->children)[i] = prog_generate_random_with_depth(terminator_prob, max_depth, depth);
    return fun_node;
}

struct node *prog_generate_random_with_depth(double terminator_prob, int max_depth, int depth)
{
    if ((depth >= max_depth) || rand_test_prob(terminator_prob)) {
        if (rand_test_prob(.5)) {
            return prog_generate_random_var();
        }
        else {
            return prog_generate_random_const();
        }
    }
    else {
        return prog_generate_random_fun(terminator_prob, max_depth, depth + 1);
    }
}

struct node *prog_generate_random(double terminator_prob, int max_depth)
{
    return prog_generate_random_with_depth(terminator_prob, max_depth, 0);
}

char *prog_to_str(struct node* prog)
{
    char *str_num, *str_fun, *p1, *p2, *p3, *str;
    size_t l;

    switch(prog->type) {
    case CONST_NODE:
        return int_to_str(prog->content);
    case VAR_NODE:
        if (prog->content < global_config->num_private_regs) {
            str_num = int_to_str(prog->content);
            l = strlen(str_num) + 2;
            str = (char *)malloc(l);
            snprintf(str, l, "#%s", str_num);
            free(str_num);
            return str;
        }
        else {
            str_num = int_to_str(prog->content - global_config->num_private_regs);
            l = strlen(str_num) + 2;
            str = (char *)malloc(l);
            snprintf(str, l, "$%s", str_num);
            free(str_num);
            return str;
        }
    case FUN_NODE:
        switch(function_arity(prog->content)) {
        case 1:
            str_fun = function_to_str(prog->content);
            p1 = prog_to_str((&prog->children)[0]);
            l = strlen(str_fun) + strlen(p1) + 2 + 1 + 1;
            str = (char *)malloc(l);
            snprintf(str, l, "(%s %s)", str_fun, p1);
            free(str_fun);
            free(p1);
            return str;
        case 2:
            str_fun = function_to_str(prog->content);
            p1 = prog_to_str((&prog->children)[0]);
            p2 = prog_to_str((&prog->children)[1]);
            l = strlen(str_fun) + strlen(p1) + strlen(p2) + 2 + 1 + 2;
            str = (char *)malloc(l);
            snprintf(str, l, "(%s %s %s)", str_fun, p1, p2);
            free(str_fun);
            free(p1);
            free(p2);
            return str;
        case 3:
            str_fun = function_to_str(prog->content);
            p1 = prog_to_str((&prog->children)[0]);
            p2 = prog_to_str((&prog->children)[1]);
            p3 = prog_to_str((&prog->children)[2]);
            l = strlen(str_fun) + strlen(p1) + strlen(p2) + 2 + 1 + 3;
            str = (char *)malloc(l);
            snprintf(str, l, "(%s %s %s %s)", str_fun, p1, p2, p3);
            free(str_fun);
            free(p1);
            free(p2);
            free(p3);
            return str;
        deafult:
            return "";
        }
    default:
        return "";
    }
}
