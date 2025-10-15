#include <bits/stdc++.h>
using namespace std;

//LEETCODE --> 2360 LONGEST CYCLE IN THE GRAPH

//SOLVED WITH YOUTUBE HELP
/*a directed graph where each node has at most one outgoing edge (represented by an array edges).

edges[i] = j means there is a directed edge from node i → j.

edges[i] = -1 means node i has no outgoing edge.

Your task is to find the length of the longest cycle in the graph.
If there is no cycle, return -1. */

/*SOLUTION : The core logic is to find cycles in the directed graph and get its length checked .To compare the lenghts of the
cycles i hvae used the path vector and the length variabele to mark the distance of the neighbour nodes form the source and 
finally use it for the length calculation*/


class Solution {
public:
    int maxcycle = -1;

    void dfs(int length, int node, vector<int>& visited, vector<int>& path, vector<int>& edges) {
        length++;
        visited[node] = 1;
        path[node] = length;

        int nbr = edges[node];
        if (nbr != -1) {
            if (!visited[nbr]) {
                dfs(length, nbr, visited, path, edges);
            } else if (visited[nbr] == 1 && path[nbr] > 0) {
                int currentlength = path[node] - path[nbr] + 1;
                maxcycle = max(maxcycle, currentlength);
            }
        }

        path[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> path(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(0, i, visited, path, edges);
            }
        }
        return maxcycle;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> edges(n);
    cout << "Enter edges (use -1 for no edge): ";
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }

    Solution obj;
    int result = obj.longestCycle(edges);

    cout << "Longest cycle length: " << result << "\n";
    return 0;
}
