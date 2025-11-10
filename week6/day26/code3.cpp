// Sum of All Divisors
#include <iostream>
using namespace std;


int divisorSum(int n) {
    int sum = 0;
    // iterate through numbers up to sqrt of n
    for (int i = 1; i * i <= n; ++i) {
        // if i is a divisor
        if (n % i == 0) {
            // add it to the sum
            sum += i;
            // if i is not the same as n / i, add n / i to the sum too
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int sum = divisorSum(n);
    cout << sum << "\n";
}