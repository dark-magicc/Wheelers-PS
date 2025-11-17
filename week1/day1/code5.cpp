/*
Write a C++ program code to get the greatest number among three numbers: number 1, number 2, and number 3 (use if condition only).
*/

#include <iostream>
using namespace std;

int main() {
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;

    if (n1 > n2 && n1 > n3){
        cout << n1 << " is the greatest";
    }
    else if (n2 > n1 && n2 > n3){
        cout << n2 << " is the greatest";
    }
    else{
        cout << n3 << " is the greatest";
    }

    return 0;
}

