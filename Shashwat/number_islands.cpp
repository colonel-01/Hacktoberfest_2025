#include <bits/stdc++.h>
using namespace std;


//LEETCODE 200---> NUMBER OF ISLANDS 
/*You’re given a grid of '1's (land) and '0's (water).
An island is a group of connected '1's (connected horizontally or vertically).
Return how many separate islands exist in the grid.*/

/*SOLUTION --> Used dfs to traverse over the graph checking for nodes with mark'1' .Since there could be more than one islands 
so the for loop in the longest cycle function was neccessary , the visited nodes are marked as '2' .*/
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};

        for (auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;

            if (0 <= ni && ni < grid.size() && 
                0 <= nj && nj < grid[0].size() && 
                grid[ni][nj] == '1') {
                
                grid[ni][nj] = '2';  // mark visited
                dfs(grid, ni, nj);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '2';   // mark visited
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    cout << "Enter grid (0 or 1 for each cell):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.numIslands(grid);
    cout << "Number of islands: " << result << "\n";

    return 0;
}
