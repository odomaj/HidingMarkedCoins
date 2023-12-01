/*
    IO.h by Alexander Odom
    CS 447 Assignment 2
    responsible for io operations and formatting data used by Sequence class
*/

#include <iostream>
#include <fstream>
#include <string>

#include "../common/Util.h"

#ifndef IO_H_
#define IO_H_

class IO
{
    public:
    IO();

    std::string readSequence();
    std::string readSequence(const std::string& filename);
    ProbabilityMatrix_t readProbabilityMatrix();
    ProbabilityMatrix_t readProbabilityMatrix(const std::string& chainFilename, const std::string& emitFilename);

    void writeSequence(const std::string& sequence);
    void writeSequence(const std::string& sequence, const std::string& filename);
};

#endif