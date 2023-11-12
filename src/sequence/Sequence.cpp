#include "Sequence.h"

Sequence::Sequence()
{

}

Sequence::Sequence(ProbabilityMatrix_t probabilityMatrix_)
{
    probabilityMatrix = probabilityMatrix_;
}

std::string Sequence::solveSequence(const std::string& sequence)
{
    if(!validSequence(sequence))
    {
        return "";
    }

    ProbableSequence_t sequenceA;
    ProbableSequence_t sequenceB;

    sequenceA.oss << COIN_A;
    sequenceB.oss << COIN_B;

    if(sequence[0] == HEADS)
    {
        sequenceA.probability = probabilityMatrix.start_a * probabilityMatrix.h_given_a;
        sequenceB.probability = probabilityMatrix.start_b * probabilityMatrix.h_given_b;
    }
    else
    {
        sequenceA.probability = probabilityMatrix.start_a * probabilityMatrix.t_given_a;
        sequenceB.probability = probabilityMatrix.start_b * probabilityMatrix.t_given_b;
    }

    for(int i = 1; i < sequence.length(); i++)
    {
        double a_to_a = sequenceA.probability * probabilityMatrix.a_to_a;
        double b_to_a = sequenceB.probability * probabilityMatrix.b_to_a;
        double a_to_b = sequenceA.probability * probabilityMatrix.a_to_b;
        double b_to_b = sequenceB.probability * probabilityMatrix.b_to_b;
        if(b_to_a > a_to_a)
        {
            sequenceA.probability = b_to_a;
            if(a_to_b > b_to_b)
            {
                sequenceB.probability = a_to_b;
                std::string temp = sequenceA.oss.str();
                sequenceA.oss.clear();
                sequenceA.oss << sequenceB.oss.str();
                sequenceB.oss.clear();
                sequenceB.oss << temp;
            }
            else
            {
                sequenceB.probability = b_to_b;
                sequenceA.oss.clear();
                sequenceA.oss << sequenceB.oss.str();
            }
        }
        else
        {
            sequenceA.probability = a_to_a;
            if(a_to_b > b_to_b)
            {
                sequenceB.probability = a_to_b;
                sequenceB.oss.clear();
                sequenceB.oss << sequenceA.oss.str();
            }
            else
            {
                sequenceB.probability = b_to_b;
            }
        }
        if(sequence[i] == HEADS)
        {
            sequenceA.probability *= probabilityMatrix.h_given_a;
            sequenceB.probability *= probabilityMatrix.h_given_b;
        }
        else
        {
            sequenceA.probability *= probabilityMatrix.t_given_a;
            sequenceB.probability *= probabilityMatrix.t_given_b;
        }
        sequenceA.oss << COIN_A;
        sequenceB.oss << COIN_B;
    }

    if(sequenceA.probability > sequenceB.probability)
    {
        return sequenceA.oss.str();
    }
    else
    {
        return sequenceB.oss.str();
    }
}

bool Sequence::validSequence(const std::string& sequence)
{
    for(int i = 0; i < sequence.length(); i++)
    {
        if(sequence[i] != HEADS && sequence[i] != TAILS)
        {
            return false;
        }
    }
    return true;
}