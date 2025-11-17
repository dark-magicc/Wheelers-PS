// Loops : (for - while - do while -nested loops)

/*Create a C++ program that displays n natural number terms and their sum.
 Sample Output: 
Enter the number of terms: 7 
The natural numbers are: up to the 7th term.
 1 2 3 4 5 6 7
 The total number of natural numbers is 28 
*/

#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << i;
        sum += i;
    }
    cout << "sum = " << sum;
    
    return 0;
}