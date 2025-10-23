#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

// Define a constant for infinity
const int INF = numeric_limits<int>::max();

/**
 * @brief Prim's algorithm to find the Minimum Spanning Tree (MST) of a connected graph.
 * * @param V The total number of vertices (nodes) in the graph (0 to V-1).
 * @param adj The graph represented as an adjacency list: 
 * vector<pair<int, int>> adj[V] where each element is (neighbor, weight).
 * @return int The total weight of the MST.
 */
int primMST(int V, const vector<pair<int, int>> adj[]) {
    // Min-heap priority queue stores tuples of (weight, vertex).
    // The heap helps in extracting the minimum-weight edge from the cut efficiently.
    // Pair: {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Key values used to pick minimum weight edge in cut (minimum weight to connect to MST)
    vector<int> key(V, INF);
    // To store parent array which in turn stores MST
    vector<int> parent(V, -1);
    // To keep track of vertices already included in MST
    vector<bool> inMST(V, false);

    // Start with the first vertex (0). Its key is 0 so it's picked first.
    int start_vertex = 0;
    key[start_vertex] = 0;
    pq.push({0, start_vertex}); // {weight, vertex}

    int mst_weight = 0;
    int edges_in_mst = 0;

    while (!pq.empty() && edges_in_mst < V) {
        // Extract the vertex 'u' with the minimum key value from the priority queue
        int u_weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // If the vertex is already in MST or the distance is outdated, skip
        if (inMST[u]) continue;

        // Add this vertex to the MST
        inMST[u] = true;
        mst_weight += u_weight;
        edges_in_mst++;

        // Traverse all adjacent vertices of u
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If v is not yet in MST and the edge (u, v) is lighter than the current
            // minimum edge connecting v to the MST, update key[v] and push to PQ.
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    // Optional: Print the edges in the MST (excluding the starting node)
    // cout << "MST Edges:" << endl;
    // for (int i = 1; i < V; ++i) {
    //     cout << "  (" << parent[i] << ", " << i << ") - Weight: " << key[i] << endl;
    // }

    return mst_weight;
}

/*
// Example Usage for Prim's
int main() {
    int V = 5; // 5 vertices (0 to 4)
    // Adjacency list: adj[u] = list of (v, weight)
    vector<pair<int, int>> adj[V]; 

    // Helper to add undirected edges
    auto add_edge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since it's an undirected graph
    };

    add_edge(0, 1, 10);
    add_edge(0, 2, 6);
    add_edge(0, 3, 5);
    add_edge(1, 3, 15);
    add_edge(2, 3, 4);
    add_edge(3, 4, 3);
    add_edge(4, 0, 7);
    
    int total_weight = primMST(V, adj);
    cout << "Total MST Weight using Prim's: " << total_weight << endl;

    return 0;
}
*/