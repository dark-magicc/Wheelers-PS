#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// BFS function (added only a vector to store distances)
void bfs(int start, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &distances)
{
    queue<int> q;
    visited[start] = true; // mart cell as visited

    distances[start] = 0;
    q.push(start); // q to oush the cell which we want to visit

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neigh : adj_list[node])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true; // mark neigh as visited
                distances[neigh] = 6 + distances[node]; // update distance with current distance +6
                q.push(neigh);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<int>> adj_list(nodes);
        for (int i = 0; i < edges; i++)
        {
            int from, to;
            cin >> from >> to;
            from--; // as he start indexing by 1
            to--;  // as he start indexing by 1
            adj_list[from].push_back(to);  // undirected
            adj_list[to].push_back(from);
        }
        int start;
        cin >> start;
        start--; // as he start indexing by 1
        vector<int> distances(nodes, -1);
        vector<bool> visited(nodes, false);
        bfs(start, adj_list, visited, distances);
        for (int i = 0; i < nodes; i++)
        {
            if (i == start)
            {
                continue;
            }
            cout << distances[i] << " ";
        }
        cout << endl;
    }

    return 0;
}