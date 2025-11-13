// Idea: Use bitmask to generate all combinations and check if any of them ==0 or 360 or 720 .....

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for (int mask = 0; mask < (1<<n); mask++)
    {
        int sum = 0;
        for (int bit = 0; bit < n ; bit++){
            if ((1<< bit) & mask)
            {
                sum += v[bit];
            }
            else{
                sum -= v[bit];
            }
            
        }
        if (sum % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
        
    }
    cout <<"NO";

    return 0;
}