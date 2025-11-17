#include <iostream>
using namespace std;
#define ll long long

// the same implementation of fun prime factorization but we add a variable to represent the max_prime_factor
ll largest_prime_factor(ll n){
    ll max_prime_factor = -1;

    for (ll i = 2; i*i <= n; i++)
    {
        while (n%i == 0)
        {
            max_prime_factor = i;
            n = n/ i;
        }
    }
    
    if (n > 1)
    {
        max_prime_factor = n;
    }
    
    return max_prime_factor;
}

int main() {
    int t;
    cin >> t;
    while (t-- >0)
    {
        ll n;
        cin >> n;
        cout << largest_prime_factor(n) << endl;
    }
    
    return 0;
}