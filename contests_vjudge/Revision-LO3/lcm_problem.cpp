// The problem asks us to find two numbers x and y between l and r where their LCM (smallest number divisible by both) is also between l and r.

/*
Idea:
For any number x, the smallest possible LCM with another number is when we pair it with 2x:   LCM(x, 2x) = 2x
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- >0)
    {
        int l, r;
        cin >> l >> r;
        // Check if we can find x such that 2x <= r and x >= l
        if (2*l <= r)
        {
            cout << l << " " << 2*l << endl;
        }
        else{
            cout << -1 << " " << -1 << endl;
        }
    }
    
    return 0;
}