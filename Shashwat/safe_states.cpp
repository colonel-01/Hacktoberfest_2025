#include<iostream>
#include<vector>
using namespace std;
/*the main logic behind this question is : we have to list out the safe nodes in ascending order .So the core logic is that 
each node which is not a part of any cycle will be a safe node , so i have implemented the same thing in the code by marking the nodes 
as 0 , 1 ,2(for safe nodes which is not a part of any cycle).Now if we think about the ascending order so since we are pushing back the
i the node form thee for loop in the main fnc so its obv in the ascending order .*/
bool dfs(int node, vector<int>& state, vector<vector<int>>& graph) {
        if (state[node] != 0) return state[node] == 2;  

        
        state[node] = 1;  
        for (auto nbr : graph[node]) {
            if (state[nbr] == 1) return false;          
            if (!dfs(nbr, state, graph)) return false;
        }
        state[node] = 2;  
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);  
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, state, graph)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
}