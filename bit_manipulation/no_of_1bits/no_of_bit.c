#include <stdio.h>

int hammingWeight(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Clears the least significant set bit
        count++;
    }
    return count;
}

int main() {
    unsigned int n = 11;
    printf("Number of set bits: %d\n", hammingWeight(n));

    n = 128;
    printf("Number of set bits: %d\n", hammingWeight(n));

    n = 2147483645;
    printf("Number of set bits: %d\n", hammingWeight(n));

    return 0;
}
