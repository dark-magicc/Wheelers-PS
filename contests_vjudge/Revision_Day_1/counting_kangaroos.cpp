// Hint: Use two pointers 
// one points to small kangaroos (start from 0)
// the other points to large kangaroo (start from N/2)
// Note: The array or vector must be sorted before using 2 pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num_of_kangaroos;
    cin >> num_of_kangaroos;

    vector<int> v(num_of_kangaroos);
    for (int i = 0; i < num_of_kangaroos; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // sort the vector
    int visible_kangaroos = num_of_kangaroos;
    int p1=0, p2=num_of_kangaroos/2; // Two Pointer

    while (p2 != num_of_kangaroos && p1!= num_of_kangaroos/2)
    {
        if((v[p1]*2) <= v[p2]){
            p1++;
            p2++;
            visible_kangaroos--;
        }
        else{
            p2++;
        }
    }
    
    cout << visible_kangaroos;
    
    
    return 0;
}