#include "stdlib.h"
#include "config.h"


int init_config()
{
    global_config = (struct config*)malloc(sizeof(struct config));
    global_config->num_private_regs = 2;
    global_config->num_public_regs = 2;
    return 1;
}

void delete_config()
{
    free(global_config);
}