#include <sstream>

#ifndef UTIL_H_
#define UTIL_H_

typedef struct
{
    double start_a;
    double start_b;

    double a_to_a;
    double a_to_b;
    double b_to_b;
    double b_to_a;

    double h_given_a;
    double t_given_a;
    double h_given_b;
    double t_given_b;
} ProbabilityMatrix_t;

typedef struct
{
    std::ostringstream oss;
    double probability;
} ProbableSequence_t;

const char COIN_A = 'X';
const char COIN_B = 'Y';
const char HEADS = 'H';
const char TAILS = 'T';


#endif