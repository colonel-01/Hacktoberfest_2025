#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

// Define a constant for infinity
const int INF = numeric_limits<int>::max();

/**
 * @brief Dijkstra's algorithm to find the shortest path from a start_node 
 * to all other nodes in a weighted graph with non-negative edges.
 * * @param graph The graph represented as an adjacency list: 
 * map<int, vector<pair<int, int>>> where:
 * - key (int) is the source node.
 * - value (vector<pair<int, int>>) is a list of (neighbor, weight) pairs.
 * @param start_node The node to start the path from.
 * @return map<int, int> A map of the shortest distance from start_node to every other reachable node.
 */
map<int, int> dijkstra(const map<int, vector<pair<int, int>>>& graph, int start_node) {
    // Stores the shortest distance from start_node to every other node.
    map<int, int> distances;
    
    // Initialize distances with INF. Get all unique nodes from the graph keys.
    for (const auto& pair : graph) {
        distances[pair.first] = INF;
        // Also ensure all nodes, even those with only incoming edges, are initialized
        for (const auto& edge : pair.second) {
            if (distances.find(edge.first) == distances.end()) {
                distances[edge.first] = INF;
            }
        }
    }

    distances[start_node] = 0;

    // Min-heap priority queue stores pairs of (distance, node).
    // Note: C++ std::priority_queue is a max-heap by default, 
    // so we store (negative distance, node) to simulate a min-heap,
    // or use greater<pair<int, int>> as the comparator.
    // We'll use greater<> here for clarity with (distance, node).
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node}); // {distance, node}

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // Optimization: If a shorter path has already been found, ignore this one.
        if (current_distance > distances[current_node]) {
            continue;
        }

        // Iterate over all neighbors of the current node
        if (graph.count(current_node)) {
            for (const auto& edge : graph.at(current_node)) {
                int neighbor = edge.first;
                int weight = edge.second;
                int distance = current_distance + weight;

                // Relaxation step: If a shorter path to the neighbor is found
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    pq.push({distance, neighbor});
                }
            }
        }
    }

    return distances;
}

/*
// Example Usage for Dijkstra's
int main() {
    map<int, vector<pair<int, int>>> graph = {
        {0, {{1, 1}, {2, 4}}},
        {1, {{2, 2}, {3, 5}}},
        {2, {{3, 1}}},
        {3, {{4, 3}}},
        {4, {}}
    };
    int start_node = 0;
    
    map<int, int> shortest_distances = dijkstra(graph, start_node);

    cout << "Dijkstra's Shortest Distances from Node " << start_node << ":" << endl;
    for (const auto& pair : shortest_distances) {
        cout << "Node " << pair.first << ": " << (pair.second == INF ? "INF" : to_string(pair.second)) << endl;
    }

    return 0;
}
*/