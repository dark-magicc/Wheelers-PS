/*
Write a C++ program that reads two numbers from the user and then displays the following:

1. If the number is greater than 10 and less than 20
2. If the number is greater than 10 or less than 20
3. If the number is not greater than 10 and less than 20
4. If the number is not greater than 10 or less than 20
*/

#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "please enter number :";
    cin >> num;
    cout << "1: " << ((num > 10) && (num < 20)) << "\n";
    cout << "2: " << ((num > 10) || (num < 20)) << "\n";
    cout << "3: " << !((num > 10) && (num < 20)) << "\n";
    cout << "4: " << !((num > 10) || (num < 20)) << "\n";
    return 0;
}
