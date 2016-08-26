#ifndef NODE_H
#define NODE_H

#define FUN_NODE 0
#define CONST_NODE 1
#define VAR_NODE 2

struct node {
    char type;
    int content;
    int child_count;
    struct node *children;
};

#endif /* NODE_H */
