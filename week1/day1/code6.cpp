/*
Write a C++ program using the switch statement to print the equivalent grade name to the given grade character. 
Assume that the variable is called grade and has the value ‘E’. 
The following table contains the different grades. Note: this is an assumed table. The output is the equivalent name of this grade.

S: Satisfy
E: Excellent
F: Fail
P: Pass
*/

#include <iostream>
using namespace std;

int main() {
    char grade = 'E';
    cin >> grade;
    
    switch (grade)
    {
    case 'E':
        cout << "Excellent";
        break;
    
    case 'S':
        cout << "Satisfy";
        break;
    case 'F':
        cout << "Fail";
        break;
    case 'P':
        cout << "Pass";
        break;
    
    default:
        cout << "invalid input";
        break;
    }
    
    return 0;
}

