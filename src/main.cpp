/*
    main.cpp by Alexander Odom
    CS 447 Assignment 2
    responsible for testing solution to solution to hiding marked coins problem
*/

#include "common/Util.h"
#include "io/IO.h"
#include "sequence/Sequence.h"

int main()
{
    IO io;
    Sequence sequence = Sequence(io.readProbabilityMatrix("../testFiles/chain.txt", "../testFiles/emit.txt"));
    io.writeSequence(sequence.solveSequence(io.readSequence("../testFiles/obs.txt")));
    return 0;
}