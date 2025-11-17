// cal in-degree for all nodes, push nodes with in-degree = 0 into queue, decrease degree of all nodes connected with that one

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void topo_sort_bfs(int nodes, vector<vector<int>> adj_list ){
    vector<int> in_degree (nodes, 0);

    for (int i = 0; i< nodes; i++){
        for (int neigh : adj_list[i]){
            in_degree[neigh]++;
        }
    }

    queue<int> q;
    for (int i = 0; i< nodes; i++){
        if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        cout << node+1 << " " ;
        q.pop();

        for (int neigh : adj_list[node]){
            in_degree[neigh] --;
            if (in_degree[neigh] == 0) q.push(neigh);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes>> edges;

    vector<vector<int>> adj_list(nodes);
    for (int i = 0; i< edges; i++){
        int from, to;
        cin>> from >> to;
        from--;to--;
        adj_list[from].push_back(to); // directed graph
    }

    topo_sort_bfs(nodes, adj_list);
    
    return 0;
}