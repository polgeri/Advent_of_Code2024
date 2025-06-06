#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSortKahn(int V, vector<vector<int>> &adj) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> topoOrder;

    // Step 1: Calculate in-degrees of all vertices
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process nodes in the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Reduce in-degree of neighbors
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Check for cycles (if topoOrder does not contain all nodes)
    if (topoOrder.size() != V) {
        cout << "The graph is not a DAG (contains cycles)." << endl;
        return;
    }

    // Print the topological order
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort (Kahn's Algorithm): ";
    topologicalSortKahn(V, adj);

    return 0;
}
