/*
Write a C++ program that reads two numbers from the user and then displays the following:

1. If the first number is equal to the second number.
2. If the first number is not equal to the second number, multiply the number by 2
 3. If the first number is greater than the second number.
4. If the first number is less than the second number.
5. If the first number is greater than or equal to the second number.
6. If the first number is less than or equal to the second number

*/

#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "please enter number 1 :";
    cin >> num1;
    cout << "please enter number 2:";
    cin >> num2;
    cout << "1: " << (num1 == num2) << "\n";
    cout << "2: " << (num1 != num2) << "\n";
    cout << "3: " << (num1 > num2) << "\n";
    cout << "4: " << (num1 < num2) << "\n";
    cout << "5: " << (num1 >= num2) << "\n";
    cout << "6 : " << (num1 <= num2) << "\n ";
    
    return 0;
}
