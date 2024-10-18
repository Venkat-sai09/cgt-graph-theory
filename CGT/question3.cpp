#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination;
    int weight;
};

void dijkstra(vector<vector<Edge>> graph, int source) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INF);
    vector<bool> visited(numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (const Edge &edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<Edge>> graph(numVertices);

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int weight;
            cin >> weight;
            if (weight != 0)
                graph[i].push_back({j, weight});
        }
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    dijkstra(graph, sourceVertex);

    return 0;
}