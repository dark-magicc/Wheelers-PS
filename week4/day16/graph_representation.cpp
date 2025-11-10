#include <iostream>
#include <vector>
using namespace std;

int main() {
    // represent of a graph using adj matrix
    // Static size:
    int mat[4][4] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };

    // If size is dynamic, use vector of vectors
    int n = 4;
    vector<vector<int>> adj_mat(n, vector<int>(n,0));
                             // no of rows,  init col (n,0)
    
    // Make user fill graph data:
    for (int i = 0; i < n; i++){
        for (int j = 0; j <n; j++){
            cout << "Enter ele [" << i << "][" <<j << "]" ;
            cin >> adj_mat[i][j];
        }
    }

    // Or initalize them yourself:
    adj_mat = {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,0},
        {1,0,0,1}
    };

    
    // If your graph is weighted, replace int with pair to add weights to connected nodes
    vector<vector<pair<int,int>>> adj_mat_weighted(n, vector<pair<int, int>>(n,{0,0}));
                             // no of rows,  init col (n,0)
    for (int i = 0; i < n; i++){
        for (int j = 0; j <n; j++){
            cout << "Enter if there is a connection [" << i << "][" <<j << "]" ;
            cin >> adj_mat_weighted[i][j].first;
            cout << "Enter the weight";
            cin >> adj_mat_weighted[i][j].second;
        }
    }    

    /*____________________________________________________________________________________*/

    // Adj list (Space Complexity : O(N+E) where N is number of nodes and E is number of edges)
                                                        // (Check edge time complexity: O(degree(Node)))

    // vector of vector (fixed number of rows but size of columns is variable according to number of nodes's neighbour)
    vector<vector<int>> adj_list (n);

    // Neighbours of node0
    adj_list[0].push_back(1);
    adj_list[0].push_back(2);

    // Neighbours of node1
    adj_list[1].push_back(0);
    adj_list[1].push_back(3);

    // Neighbours of node2
    adj_list[2].push_back(0);
    adj_list[2].push_back(3);
    
    // Neighbours of node3
    adj_list[3].push_back(1);
    adj_list[3].push_back(2);

    return 0;
}