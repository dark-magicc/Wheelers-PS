#include <iostream>
#include <vector>
using namespace std;

// all possible direction to get adj of a cell
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

//  Try to visit all adj of a cell using DFS
void dfs(vector<string> &grid, vector<vector<bool>> &visited, int x, int y, int rows, int columns)
{
    visited[x][y] = true; // mark it as visited

    for (int i = 0; i < 4; i++) // try to get all adj of that cell
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < columns) // inside grid
        {
            if (grid[new_x][new_y] == '.' && !visited[new_x][new_y]) // 2 condition: check that cell contain a '.', and it is not visited
            {
                dfs(grid, visited, new_x, new_y, rows, columns); // call the fun
            }
        }
    }
}

int main()
{
    int rows, columns; // rows, columms
    cin >> rows >> columns;

    vector<string> grid(rows);
    vector<vector<bool>> visited(rows, vector<bool>(columns, false));

    for (int i = 0; i < rows; i++)
    {
        cin >> grid[i]; // enter the input
    }
    int count = 0;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < columns; y++)
        {
            if (grid[x][y] == '.' && !visited[x][y])
            {
                count++; // number of rooms ++ as ther are a new component
                dfs(grid, visited, x, y, rows, columns);
            }
        }
    }
    cout << count;

    return 0;
}