// Idea:
// Create 2 variables: open: to indicate that there is an open bracket, operation to store num of operations
// if found a close bracket: open--
// if a close bracket came first, convert it to open (operation++), open=1
// then if there is remining brackets, will add open/2 to operation

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int test_case_number = 1;
    while (true)
    {
        int open= 0 ;
        int operation = 0;
        getline(cin,s);
        if (s == "---")
        {
            break;
        }
        for (char c : s){
            if (c == '{'){
                open++;
            }
            else{
                if (open >0) open--;
                else{
                    operation++;
                    open=1;
                }
            }
        }
        operation += (open/2);
        cout << test_case_number <<". " << operation << endl;
        test_case_number++;
    }
     
    return 0;
}

