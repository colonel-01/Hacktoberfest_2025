#include <iostream>
using namespace std;
int n, m; //n is the number of nodes, m is the number of edges
const int MAXN = 100; //maximum number of nodes
const int INF = 1e9; //infinity
int adj[MAXN][MAXN]; //adjacency matrix to store the weight of each edge
int dist[MAXN][MAXN]; //2D array to store the distance between every pair
int main(){
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++) { 
        if (i == j) dist[i][j] = 0; //The distance between each node and itself is 0
        else if (adj[i][j]) dist[i][j] = adj[i][j]; //between another node with an edge is the weight
        else dist[i][j] = INF; //Everything else is infinity
    } 
}//Store the distance between every pair of nodes in a 2D array. 

for (int k = 1; k <= n; k++) {//loop through every node to act as an intermediate node
    //go through every 2 nodes that are also connected to this node
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
        //update distance
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]); 
        } 
    } 
}}