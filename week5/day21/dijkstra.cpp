#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // for INT_MAX
using namespace std;

void dijkstra(int start, 
    vector<vector<pair<int,int>>>& adj_list, 
    int nodes)
{
    vector<int> dis (nodes, INT_MAX);
    vector<bool> visited(nodes, false);

    priority_queue<
        pair<int, int>,  // element type
        vector<pair<int, int>>, // container type
        greater<pair<int, int>> // fun to detect ascending or descinging
    > pq;

    dis[start] = 0;

    pq.push({0, start});

    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();

        if (visited[node] == true){
            // visited 
            continue;
        }
        visited[node] = true;
        
        for ( auto adj : adj_list[node]){
            int neigh = adj.first;
            int weight = adj.second;
            // relaxation

            if (dis[node] + weight < dis[neigh]){
                dis[neigh] = dis[node] + weight;
                pq.push({dis[neigh], neigh});
            }

        }

    }

    for (int i = 0; i < nodes; i++){
        if (dis[i] == INT_MAX){
            cout << "can reach node " << i;
        }
        else{
            cout << "distance from " 
             << start << "to: " << i 
             << "is " << dis[i] << endl;
        }
    }

}   

int main() {
    int nodes, edges;

    cin >> nodes >> edges;

    vector<vector<pair<int,int>>> adj_list (nodes);

    for (int i =0; i< edges; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        // from--;
        // to--;
        adj_list[from] .push_back({to, weight});
        // adj_list[to] .push_back({from, weight});

    }
    int start;
    cin >> start;
    
    dijkstra(start, adj_list, nodes);

    return 0;
}