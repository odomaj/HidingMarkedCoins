#ifndef UTIL_H_
#define UTIL_H_

typedef struct
{
    double a_to_a;
    double a_to_b;
    double b_to_b;
    double b_to_a;

    double h_given_a;
    double t_given_a;
    double h_given_b;
    double t_given_b;
} ProbabilityMatrix_t;

#endif