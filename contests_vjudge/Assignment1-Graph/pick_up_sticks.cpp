// Given some sticks (for example stick3 over stick 2, stick 2 over stick 1: so you should pick stick 3 then 2 then 1)
// Idea: use topological sort
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topological_sort(vector<vector<int>> &adj_list, int nodes)
{
    vector<int> in_degree(nodes, 0);
    queue<int> q;
    // calculate in degree for all nodes
    for (int i = 0; i < nodes; i++)
    {
        for (int neigh : adj_list[i])
        {
            in_degree[neigh]++;
        }
    }

    // check which one has a zero in degree
    for (int i = 0; i < nodes; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    // That means you can't do anything as at first no one has indegree = 0
    if (q.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node + 1 << endl;

        for (int neigh : adj_list[node])
        {
            // Update indegree
            in_degree[neigh]--;

            // check if indegree == 0: push to q
            if (in_degree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
}

int main()
{
    while (true)
    {
        int nodes, edges;
        cin >> nodes >> edges;
        if (nodes == 0 && edges == 0)
        {
            break;
        }

        vector<vector<int>> adj_list(nodes);
        for (int i = 0; i < edges; i++)
        {
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            adj_list[from].push_back(to); // directed graph
        }
        topological_sort(adj_list, nodes);  // apply topological sort
    }

    return 0;
}