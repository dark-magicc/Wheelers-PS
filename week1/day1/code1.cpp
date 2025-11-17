// revision on basic c++
// data types, inputs, outputs, assignment operators, comparison operators,

// Test1:
// reads two numbers from the user and then displays the following:
/*
1. The summation of the two numbers. 
2. The difference between the first number and the second number. 
3. The difference between the second number and the first number. 
4. The multiplication between the two numbers.
5. The division between the first number and the second number (the first divided by the second).
*/


#include <iostream>
using namespace std;

int main()
{
    int first_num, second_num;
    cout << "please enter the first number:";
    cin >> first_num;
    cout << "please enter the second number:";
    cin >> second_num;
    cout << "1: " << first_num + second_num << "\n";
    cout << "2: " << first_num - second_num << "\n";
    cout << "3: " << second_num - first_num << "\n";
    cout << "4: " << first_num * second_num << "\n";
    cout << "5: " << first_num / second_num << "\n";
    return 0;
}
