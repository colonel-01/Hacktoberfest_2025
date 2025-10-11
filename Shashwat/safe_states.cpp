#include<iostream>
using namespace std;
bool dfs(int node, vector<int>& state, vector<vector<int>>& graph) {
        if (state[node] != 0) return state[node] == 2;  // already processed
        
        state[node] = 1;  // mark as visiting
        for (auto nbr : graph[node]) {
            if (state[nbr] == 1) return false;          // found a cycle
            if (!dfs(nbr, state, graph)) return false;
        }
        state[node] = 2;  // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);  // 0=unvisited, 1=visiting, 2=safe
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, state, graph)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
}