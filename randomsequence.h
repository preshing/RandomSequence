#ifndef __RANDOM_SEQUENCE_H__
#define __RANDOM_SEQUENCE_H__


class RandomSequenceOfUnique
{
private:
    unsigned int m_index;
    unsigned int m_intermediateOffset;

    static unsigned int shuffleQPR(unsigned int x)
    {
        static const unsigned int prime = 4294967291u;
        if (x >= prime)
            return x;  // The 5 integers out of range are mapped to themselves.
        unsigned int residue = ((unsigned long long) x * x) % prime;
        return (x <= prime / 2) ? residue : prime - residue;
    }

public:
    RandomSequenceOfUnique(unsigned int seedBase, unsigned int seedOffset)
    {
        m_index = shuffleQPR(shuffleQPR(seedBase) + 0x682f0161);
        m_intermediateOffset = shuffleQPR(shuffleQPR(seedOffset) + 0x46790905);
    }

    unsigned int next()
    {
        return shuffleQPR((shuffleQPR(m_index++) + m_intermediateOffset) ^ 0x5bf03635);
    }
};


#endif // __RANDOM_SEQUENCE_H__

