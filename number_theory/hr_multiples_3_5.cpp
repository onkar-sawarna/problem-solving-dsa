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
