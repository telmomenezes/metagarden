#include <time.h>
#include <stdlib.h>


void rand_init()
{
    srand(time(NULL));
}


int rand_test_prob(double prob)
{
    double r = ((double)rand()) / ((double)RAND_MAX);
    return r < prob;
}

int rand_uniform()
{
    return rand();
}


int rand_uniform_max(int max)
{
    return rand_uniform() % max;
}