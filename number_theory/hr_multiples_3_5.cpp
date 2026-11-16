#include <iostream>

long long sumDivisibleBy(long long n, long long a) {
    long long p = (n - 1) / a;
    return a * (p * (p + 1)) / 2;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        long long sum3 = sumDivisibleBy(n, 3);
        long long sum5 = sumDivisibleBy(n, 5);
        long long sum15 = sumDivisibleBy(n, 15);
        long long result = sum3 + sum5 - sum15;
        std::cout << result << std::endl;
    }
    return 0;
}

// Time Complexity: O(t)
// Space Complexity: O(1)
// Pattern: Number Theory - Inclusion exclusion
// explanation:
/*
Each test wants the sum of multiples of 3 or 5 that are strictly below n.
sumDivisibleBy(n, a) evaluates a * p * (p+1) / 2 with p = (n-1)/a.
Multiples of 15 are subtracted so they are not added for both 3 and 5.
Each test is a constant amount of arithmetic, and no multiple list is built.
*/
