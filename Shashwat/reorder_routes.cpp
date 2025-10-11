#include <iostream>
#include <vector>
using namespace std;

//REORDER ROUTES PROBLEM LEETCODE 1446
//LOGIC :- SO WE MAEK A SEPARATE BACKWARD NBR GRAPH TO STORE THE OPPOSITE CONNECTIONS OF WHATEVER GIVEN,NOW HERE COMES TWO SECTIONS
//A)THE FOR_NBR LOOP TRAVERSES ALL THE FOR CONNECTIONS AND INC THE ANS TO MARK THAT THESE ROUTES NEEDED TO BE CHANGED
//B)THE BACKWARD NBR MAKES SURE TO TRAVERS ALL THOSE NODE WHICH COULDNOT BE TRAVERSED FROM THE SOURCE AND IT FURTHER AGAIN CALL 
//THE DFS FUNCTION TO MAKE SURE TO CHANGE THE ROUTES AND TRAVERSE EACH AND EVERY NODE
void dfs(int node, int &ans, vector<int> &visited,
         vector<vector<int>> &connections,
         vector<vector<int>> &for_nbr,
         vector<vector<int>> &back_nbr) {
    visited[node] = 1;
    for (int nbr : for_nbr[node]) {
        if (!visited[nbr]) {
            ans++;
            dfs(nbr, ans, visited, connections, for_nbr, back_nbr);
        }
    }
    for (int nbr : back_nbr[node]) {
        if (!visited[nbr]) {
            dfs(nbr, ans, visited, connections, for_nbr, back_nbr);
        }
    }
}

int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<int>> for_nbr(n);
    vector<vector<int>> back_nbr(n);
    vector<int> visited(n, 0);

    for (auto &edge : connections) {
        int a = edge[0];
        int b = edge[1];
        for_nbr[a].push_back(b);
        back_nbr[b].push_back(a);
    }

    int ans = 0;
    dfs(0, ans, visited, connections, for_nbr, back_nbr);
    return ans;
}

int main() {
  
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}
    };

    cout << "Minimum edges to reorder: " << minReorder(n, connections) << endl;
    return 0;
}
