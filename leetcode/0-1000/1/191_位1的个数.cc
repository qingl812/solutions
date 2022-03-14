#include "common.h"

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

TEST(solution, hammingWeight) {
    bitset<32> bits;

    bits = bitset<32>("00000000000000000000000000001011");
    EXPECT_EQ(3, hammingWeight(bits.to_ulong()));

    bits = bitset<32>("00000000000000000000000010000000");
    EXPECT_EQ(1, hammingWeight(bits.to_ulong()));

    bits = bitset<32>("11111111111111111111111111111101");
    EXPECT_EQ(31, hammingWeight(bits.to_ulong()));
}