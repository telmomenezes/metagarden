#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "prog.h"
#include "node.h"
#include "rand.h"


int main(int argc, char *argv[])
{
    printf("MetaGarden.\n");

    rand_init();
    init_config();

    struct node *prog = prog_generate_random(0.5, 5);
    printf("prog size: %u\n", prog_size(prog));
    printf("%s\n", prog_to_str(prog));

    delete_config();

    return 0;
}