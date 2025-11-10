// Display pattern
/*
1
12
123
1234
*/

#include <iostream>
using namespace std;

int main() {
    int max_num = 4;
    for (int i = 1; i <= max_num ; i++){
        for (int j = 0 ; j < i ; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
    return 0;
}