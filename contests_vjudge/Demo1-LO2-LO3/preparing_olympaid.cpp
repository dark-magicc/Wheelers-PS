// Idea: use bitmask to generate all possible combinations of problems and check if that combination meet the conditions

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, min_sum, max_sum, min_difference;
    cin >> n >> min_sum >> max_sum >> min_difference;
    vector<int> v(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>> v[i];
    }
    
    int possible_solutions = 0;
    for (int mask = 0; mask < (1<<n); mask++)
    {
        
        int min_ele = INT_MAX;
        int max_ele = -INT_MAX;
        int sum = 0;
        for (int bit = 0; bit < n; bit++){
            if ((1<< bit) & mask)
            {
                sum += v[bit];
                min_ele = min(min_ele, v[bit]);
                max_ele = max(max_ele, v[bit]);
            }
            
        }
        
        if (sum >= min_sum && sum <= max_sum && (max_ele - min_ele) >= min_difference)
        {
            possible_solutions++;
        }
        
    }
    cout << possible_solutions;
    
    
    return 0;
}