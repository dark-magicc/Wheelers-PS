// Problem1

#include <iostream>
using namespace std;

int main() {
    int num; 
    bool is_prime = true;
    cout << "Enter a number";
    cin >> num;
    
    
    if ( num <= 1){
        cout << "Not prime as prime numbers must be positive and greater that one";
    }
    else{
        for (int i=2; i < num; i++){
            if ((num % i) == 0){ // Accept divide to that number so num is not prime
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            cout << "Prime";
        }
        else{
            cout << "Not Prime";
        }
    }
    return 0;
}

