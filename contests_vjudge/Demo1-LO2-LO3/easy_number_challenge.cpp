

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int mod = 1073741824 ;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int>divisors(a*b*c+1, 0);

    for (int i = 1; i <= a*b*c; i++)
    {
        for (int j = i; j <= a*b*c; j+=i)
        {
            divisors[j]++;
        }
    }
    ll sum = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++){
            for (int k = 1; k <= c; k++){
                sum = (sum+ divisors[i*j*k]) % mod;
            }
        }
    }
    cout << sum;


    return 0;
}