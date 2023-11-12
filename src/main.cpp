
#include "common/Util.h"
#include "io/IO.h"
#include "sequence/Sequence.h"

int main()
{
    IO io;
    Sequence sequence = Sequence(io.readProbabilityMatrix());
    io.writeSequence(sequence.solveSequence(io.readSequence()));
    return 0;
}