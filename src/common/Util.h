/*
    Util.h by Alexander Odom
    CS 447 Assignment 2
    contains structs and values used by IO and Sequence classes
*/

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
const char HEADS = '1';
const char TAILS = '0';


#endif