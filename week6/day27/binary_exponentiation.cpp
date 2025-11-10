#include <iostream>
using namespace std;

int binary_exponentiation(int base, int power) {
    int ret = 1;
    while (power > 0) {
        if (power % 2 != 0)
            ret = ret * base;
        base = base * base;
        power /= 2;
    }
    return ret;
}

int main() {
    int base, power;
    cin >> base >> power;
    cout << binary_exponentiation(base, power);
    return 0;
}
