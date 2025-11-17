/*
-----------------------------------------------------------
Problem: COMMON CHILD (Longest Common Subsequence Problem)
-----------------------------------------------------------
Idea:
- Given two strings, find the length of the longest string
  that can be formed from both of them by deleting some
  characters without changing the order of the remaining ones.

Example:
a = "ABCD"
b = "ABDC"
→ Common subsequences: "ABC", "ABD", "ACD", "BCD", "ADC"
→ Longest one = "ABC" (or "ABD")
→ Answer = 3

Approach:
- This is a classic "Longest Common Subsequence" (LCS) problem.
- Use Dynamic Programming (DP) to avoid recomputation.

-----------------------------------------------------------
Dynamic Programming Approach
-----------------------------------------------------------

We define:
dp[i][j] = length of the longest common subsequence (LCS)
           between first i characters of string a
           and first j characters of string b.

-----------------------------------------------------------
Recurrence Relation
-----------------------------------------------------------

We fill the table using these rules:

1. Base Case:
   - dp[0][j] = 0  (if a is empty, LCS = 0)
   - dp[i][0] = 0  (if b is empty, LCS = 0)

2. If last characters match:
      a[i-1] == b[j-1]
      → dp[i][j] = dp[i-1][j-1] + 1
   (Explanation: we extend the LCS by this matching character)

3. If last characters do not match:
      a[i-1] != b[j-1]
      → dp[i][j] = max(dp[i-1][j], dp[i][j-1])
   (Explanation: we skip one character from either a or b
                 and take the best result)

-----------------------------------------------------------
Example Table Construction (a="ABCD", b="ABDC")
-----------------------------------------------------------

Let’s fill dp step-by-step (showing only main logic):

        ""  A  B  D  C
     ""  0  0  0  0  0
     A   0  1  1  1  1
     B   0  1  2  2  2
     C   0  1  2  2  3
     D   0  1  2  3  3

→ dp[4][4] = 3 → final answer
-----------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int longest_child(string a, string b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[a.size()][b.size()];
}

int main()
{
    string a = "abcd";
    string b = "abdc";
    cin >> a >> b;
    cout << longest_child(a, b);

    return 0;
}