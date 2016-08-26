#ifndef CONFIG_H
#define CONFIG_H


struct config {
    int num_private_regs;
    int num_public_regs;
};

struct config* global_config;

int init_config();

void delete_config();

#endif /* CONFIG_H */
