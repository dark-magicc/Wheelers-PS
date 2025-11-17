// Idea: To store all characters in a set (set doesn't allow duplicated)
// Then: Check if size of set is 26 (number of chars in alphabet), so it will be pangram
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int no_of_alphbets = 26;

    int str_size;
    cin >> str_size;

    string s;
    cin >> s;

    set<char> txt;

    for (int i = 0; i < str_size; i++)
    {
        txt.insert(tolower(s[i])); // to make sure to transform all chars to lowercase
    }
    if (txt.size() == no_of_alphbets)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}