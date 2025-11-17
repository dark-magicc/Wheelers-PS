// To calculate score: by itself and its just previous consecutive ‘O’s
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    string s;
    getline(cin, s);

    while (no_of_test_cases-- > 0)
    {
        int score = 0;
        int acc_score = 0; // to store number of consecutive ‘O’s
        getline(cin, s);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'O')
            {
                acc_score++;
                score += acc_score; // update score
            }
            else
            {
                acc_score = 0; // reset consecutive ‘O’s
            }
        }
        cout << score << endl;
    }

    return 0;
}