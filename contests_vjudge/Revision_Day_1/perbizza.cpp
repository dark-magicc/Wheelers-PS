// Idea: 
// You will need 3 STLs
// Queue for storing customers who came first
// Priority Queue for storing customers and expected money with ascending order
// Vector of bool (to store that customer is served before or not)

// User will input n queries
// there are 3 cases of inputs
// case 1 :  a new customer come with estimated money to spent (m)
// case 2 :  Monocarp is free to serve a customer (who came first)
// case 3 :  Polycarp is free to serve a customer which is expected to spend the largest amount of money 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if (a.first == b.first)
        {
            return a.second > b.second;  // min-heap for second (if the customers came with the same expected money, pq should output the customer who came first)
        }
        return a.first < b.first;   // max-heap (as default, we store first the one who expected to pay more)
        
    }
};


int main() {
    int n;
    cin >> n;

    queue<int> customers;
    priority_queue<pair<int, int>, vector<pair<int,int>> , cmp> pq;
    vector<bool> served(n+1, false);

    vector<int> output; // to store output

    int user_id = 1;
    while (n-- > 0)
    {
        int current_input;
        cin >> current_input;

        switch (current_input)
        {
        case 1:
            int money;
            cin >> money;
            customers.push(user_id);
            pq.push({money, user_id});
            user_id++;
            break;
        case 2:
            while (!customers.empty() && served[customers.front()] == true)
            {
                customers.pop();
            }
            if (!customers.empty())
            {
                output.push_back(customers.front());
                served[customers.front()] = true;
                customers.pop();
            }
            
            break;
        case 3:
            while (!pq.empty() && served[pq.top().second] == true)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                output.push_back( pq.top().second);
                served[pq.top().second] = true;
                pq.pop();
            }
            break;
        
        default:
            break;
        }
    }
    
    for (int i : output){
        cout << i << " ";
    }
    
    return 0;
}