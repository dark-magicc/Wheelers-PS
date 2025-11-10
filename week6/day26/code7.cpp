// Sieve of Eratosthenes
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e7;
bool is_prime[N + 1];

void sieve() {
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    sieve();

    // Example: print all primes up to 100
    for (int i = 2; i <= 100; ++i) {
        if (is_prime[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
