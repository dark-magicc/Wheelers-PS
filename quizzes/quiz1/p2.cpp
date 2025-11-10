// Problem 2


#include <iostream>
using namespace std;

int main() {
    int arr[6]; //Fixed size, if you want to make it dynamic use vector
    int i=0;
    while(i <6){
        cout << "Enter element with index " << i << endl;
        cin >> arr[i];
        i++;
    }
    int min = arr[0];
    int max = arr[0];
    int sum = 0;

    for (int j : arr){
        if (j < min){
            min = j;
        }
        if (j > max){
            max =j;
        }
        sum += j;
    }
    cout << "Min element is : " << min << endl;
    cout << "Max element is : " << max << endl;
    cout << "Array avg is : " << sum/6.0 << endl;

    return 0;
}