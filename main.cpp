#include "randomsequence.h"
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <string.h>


// 0 indicates success
int verifyUnique()
{
    unsigned char* bitfield = new unsigned char[0x20000000];
    memset(bitfield, 0, 0x20000000);
    unsigned int seed = (unsigned int) time(NULL);
    RandomSequenceOfUnique rsu(seed, seed + 1);
    unsigned int i = 0;
    do
    {
        if ((i & 0xffffff) == 0)
            printf("Progress: %d/256\n", i >> 24);
        unsigned int x = rsu.next();
        unsigned char *byte = bitfield + (x >> 3);
        unsigned char bit = 1 << (x & 7);
        if ((*byte & bit) != 0)
            return 1;  // failure
        *byte |= bit;
    }
    while (++i != 0);
    return 0;	// success
}

int dump()
{
    unsigned int seed = (unsigned int) time(NULL);
	RandomSequenceOfUnique rsu(seed, seed + 1);
    unsigned int i = 0;
    do
    {
		printf("0x%08x\n", rsu.next());
	}
	while (++i != 0);
	return 0;
}

int main(int argc, const char* argv[])
{
	if (argc == 2 && strcmp(argv[1], "verifyunique") == 0)
		return verifyUnique();
	else if (argc == 2 && strcmp(argv[1], "dump") == 0)
		return dump();
	fputs("Invalid arguments\n", stderr);
	return 1;
}
