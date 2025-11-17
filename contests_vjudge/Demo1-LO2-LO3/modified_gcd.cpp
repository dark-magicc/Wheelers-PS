// Given two numbers and required to find the greatest common divisor in a range
// Idea: Start by finding gcd then find all divisors of that gcd
// then take the range (low and high) and check the greatest divisor in that range

#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a%b);
}



int main() {
    int a, b;
    cin >> a >> b;

    // Get GCD of a number
    int gcd = GCD(a,b);

    // Get all divisors
    vector<int> divisors;
    for (int i = 1; i*i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            divisors.push_back(i);
            if (gcd/i != i)
            {
                divisors.push_back(gcd/i);
            }
        }
    }
    
    // Number of test cases
    int t;
    cin >> t;
    while (t-- >0)
    {
        int low, high;
        int greatest_divisor = -1;
        cin >> low >> high;

        for (int i : divisors){
            if (i>= low && i <= high)  // check if that number is within range
            {
                greatest_divisor = max(greatest_divisor, i);  // update value of greater divisor
            }
        }
        cout << greatest_divisor << endl;
    }
    

    return 0;
}