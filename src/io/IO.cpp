/*
    IO.cpp by Alexander Odom
    CS 447 Assignment 2
*/

#include "IO.h"

IO::IO()
{

}

std::string IO::readSequence()
{
    std::string sequence;
    std::cin >> sequence;
    return sequence;
}

std::string IO::readSequence(const std::string& filename)
{
    std::ostringstream sequence;
    std::ifstream in;
    in.open(filename);
    while(!in.fail())
    {
        std::string nextSequence;
        in >> nextSequence;
        sequence << nextSequence;
    }
    in.close();
    return sequence.str();
}

ProbabilityMatrix_t IO::readProbabilityMatrix()
{
    ProbabilityMatrix_t probabliityMatrix;

    std::cin >> probabliityMatrix.a_to_a; 
    std::cin >> probabliityMatrix.b_to_b;
    std::cin >> probabliityMatrix.a_to_b;
    std::cin >> probabliityMatrix.b_to_a;
    std::cin >> probabliityMatrix.h_given_a;
    std::cin >> probabliityMatrix.h_given_b;

    probabliityMatrix.t_given_a = 1 - probabliityMatrix.h_given_a;
    probabliityMatrix.t_given_b = 1 - probabliityMatrix.h_given_b;

    probabliityMatrix.start_a = probabliityMatrix.a_to_a;
    probabliityMatrix.start_b = probabliityMatrix.a_to_b;

    return probabliityMatrix;
}

ProbabilityMatrix_t IO::readProbabilityMatrix(const std::string& chainFilename, const std::string& emitFilename)
{
    ProbabilityMatrix_t probabliityMatrix;

    std::ifstream in;
    in.open(chainFilename);
    in >> probabliityMatrix.a_to_a; 
    in >> probabliityMatrix.b_to_b;
    in >> probabliityMatrix.a_to_b;
    in >> probabliityMatrix.b_to_a;
    in.close();
    in.open(emitFilename);
    in >> probabliityMatrix.h_given_a;
    in >> probabliityMatrix.h_given_b;
    in.close();

    probabliityMatrix.t_given_a = 1 - probabliityMatrix.h_given_a;
    probabliityMatrix.t_given_b = 1 - probabliityMatrix.h_given_b;

    probabliityMatrix.start_a = probabliityMatrix.a_to_a;
    probabliityMatrix.start_b = probabliityMatrix.a_to_b;

    return probabliityMatrix;
}

void IO::writeSequence(const std::string& sequence)
{
    std::cout << sequence << '\n';
}

void IO::writeSequence(const std::string& sequence, const std::string& filename)
{
    std::ofstream out;
    out.open(filename);
    out << sequence << std::endl;
    out.close();
}