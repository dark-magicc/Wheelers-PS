// We want to calculate (5^n)%m
// Easist solution: to print 25 as the result in  all cases equal 25
// But we will practice on binary exponentition 
#include <iostream>
#define ll long long
using namespace std;

ll mul(ll a, ll b, ll m){
    return ((a%m)*(b%m))%m;
}

ll binary_expo(ll base, ll power, ll mod){
    ll res = 1;
    while (power>0)
    {
        if (power %2 ==1)
        {
            res = mul(res, base, mod);
        }
        base = mul(base, base, mod);
        power = power /2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    ll mod = 100;
    ll base = 5;

    cout << binary_expo(base, n, mod);

    return 0;
}