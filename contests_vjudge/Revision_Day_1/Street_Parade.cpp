// Idea: to use the stack as the side road
#include <iostream>
#include <stack>
using namespace std;

int main()
{

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        
        int expected = 1;
        stack<int> st;
        int truck;

        for (int i = 0; i < n; i++)
        {
            cin >> truck;
            // check input and top of stack
            if (truck == expected)
            {
                expected++;
            }
            else if (!st.empty())
            {
                while (!st.empty() && st.top() == expected)
                {
                    expected++;
                    st.pop();
                }
                st.push(truck);  // push the truck into the stack
            }
            else
            {
                st.push(truck);  // push the truck into the stack
            }
        }

        while (!st.empty() && st.top() == expected)
        {
            expected++;
            st.pop();
        }

        if (st.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}