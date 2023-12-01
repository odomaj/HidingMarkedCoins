/*
    Sequence.h by Alexander Odom
    CS 447 Assignment 2
    responsible for finding solving the hiding marked coins problem
*/

#include <string>

#include "../common/Util.h"

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Sequence
{
    public:
    Sequence();
    Sequence(ProbabilityMatrix_t probabilityMatrix_);
    std::string solveSequence(const std::string& sequence);
    private:
    ProbabilityMatrix_t probabilityMatrix;
    bool validSequence(const std::string& sequence);
};

#endif