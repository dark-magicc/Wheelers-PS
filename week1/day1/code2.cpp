/*
Write a C++ program that reads two numbers from the user and then displays the following:
1. Add 9 to the number.
2. Subtract 9 from the number.
3. Multiply the number by 2
4. Divide the number over 3
5. Find the remainder of dividing the number over 5
6. Apply and operation between the number and the number 3
7. Apply or operation between the number and the number 3
8. Shift the input value by 2 to the right.
9. Shift the input value by 2 to the left
*/

#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "please enter the number:";
    cin >> num;
    cout << "1: " << (num += 9) << "\n";
    cout << "2: " << (num -= 9) << "\n";
    cout << "3: " << (num *= 2) << "\n";
    cout << "4: " << (num /= 3) << "\n";
    cout << "5: " << (num %= 5) << "\n";
    cout << "6 : " << (num &= 3) << "\n ";
    cout << "7 : " << (num |= 3) << "\n ";    
    cout << "8 : " << (num >>= 2) << "\n "; 
    cout << "9 : " << (num <<= 2) << "\n "; 
    
    return 0;
}
