// Dijkstra Code
// Idea: He wants to check minimun latency to send an email (min path)
// Apply dijkstra algoirthm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dijkstra(vector<vector<pair<int,int>>>& adj_list, int start, int end,int nodes){
    vector<bool> visited(nodes, false);
    vector<int> dis(nodes, INT_MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dis[start] = 0;
    pq.push({dis[start], start});

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if (visited[node] == true)
        {
            continue;
        }
        visited[node] = true;

        for (auto adj : adj_list[node]){
            int neigh = adj.first;
            int weight  = adj.second;

            // relaxation
            if (dis[node] + weight < dis[neigh])
            {
                dis[neigh] = dis[node] + weight;
                pq.push({ dis[neigh], neigh});
            }
        }
    }

    return dis[end];

}

int main() {
    int t;
    cin >> t;
    int index = 1;
    while (t-- >0)
    {
        int nodes, edges, start, end;
        cin >> nodes >> edges >> start >> end;

        vector<vector<pair<int,int>>> adj_list(nodes);
        for (int i = 0; i < edges; i++)
        {
            int from , to, weight;
            cin >> from >> to >> weight;
            adj_list[from].push_back({to, weight});
            adj_list[to].push_back({from, weight});
        }
        
        int res = dijkstra(adj_list, start, end, nodes);
        if (res == INT_MAX)
        {
            cout << "Case #" << index << ": " << "unreachable" << endl;
        }
        else{
            cout << "Case #" << index << ": " << res << endl;            
        }
        index++;
    }
    
    return 0;
}