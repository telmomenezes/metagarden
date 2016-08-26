#ifndef PROG_H
#define PROG_H

#include "node.h"


unsigned int prog_size(struct node *prog);

struct node *prog_generate_random(double terminator_prob, int max_depth);

struct node *prog_generate_random_with_depth(double terminator_prob, int max_depth, int depth);

char *prog_to_str(struct node* prog);

#endif /* PROG_H */
