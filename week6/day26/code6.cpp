// Prime factorization
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> primeFactors;
    // search for the smallest factor of n
    for (int i = 2; i * i <= n; ++i) {
        int power = 0;
        while (n % i == 0) { // i is the smallest prime factor of n
            ++power;
            n /= i; // remove i from n and repeat the process
        }
        if (power > 0) primeFactors.push_back({i, power});
    }
    // if n is not 1, it must be a prime number
    if (n != 1) primeFactors.push_back({n, 1});
    return primeFactors;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> primeFactors = factorize(n);
    for (pair<int,int> f : primeFactors) {
        cout << f.first << " ^ " << f.second << "\n";
    }
}