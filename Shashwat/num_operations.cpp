#include <iostream>
#include <vector>
using namespace std;

/*Question-->You’re given n computers and some connections between them. You can rewire any existing cable between two computers. The task is to find the minimum number of operations needed to connect all computers into one network. If not enough cables exist, return -1. */

/*Approacch--> If the number of connections is less than n-1, it’s impossible to connect all computers. Otherwise, build an adjacency list and use DFS to count how many connected components exist. To connect all of them into a single network, we need (components - 1) operations, since each operation can connect two separate components.*/
class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        visited[node] = 1;
        for (auto it : graph[node]) {
            if (!visited[it]) {
                dfs(graph, visited, it);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<vector<int>> graph(n);
        for (auto &edge : connections) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                components++;
            }
        }

        return components - 1;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}
    };

    cout << sol.makeConnected(n, connections);
    return 0;
}