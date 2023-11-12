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
};

#endif