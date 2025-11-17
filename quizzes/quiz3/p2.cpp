// Dijkstra shortest path

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// fun will return shortest distance from src to des
int dijkstra(int src, vector<vector<pair<int,int>>>& adj_list, int nodes, int des){
    vector<bool> visited (nodes, false);
    vector<int> dis (nodes, INT_MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dis[src] = 0;
    pq.push({0, src}); //push to queue first entry (dis of src(0), src );

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        
        if (visited[node] == true){
            continue;
        }
        visited[node] == true;

        for (auto adj: adj_list[node]){
            int neigh = adj.first;
            int weight  = adj.second;

            // relaxation
            if (dis[node] + weight < dis[neigh]){
                dis[neigh] = dis[node] + weight;
                pq.push({dis[neigh], neigh});
            }
        }
    }

    for (int i = 0; i < nodes; i++){
        if (i == des){
            if (dis[i] == INT_MAX) return -1;
            else return dis[i];
        }
    }
    
    return -1; // I put only to avoid warning
}

int main() {
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while (no_of_test_cases > 0)
    {
        int nodes, edges;
        cin >> nodes >> edges;

        vector<vector<pair<int,int>>> adj_list(nodes);

        for (int i = 0; i<edges; i++){
            int from, to, weight;
            cin >> from >> to >> weight;

            from--;to--;
            adj_list[from].push_back({to, weight});
        }
        int src, des;
        cin >> src >> des;
        src --; des--;
        int res = dijkstra(src, adj_list, nodes, des);

        if (res == -1) cout << "NO" << endl;
        else cout << res << endl;

        no_of_test_cases--;
    }
    

    
    return 0;
}