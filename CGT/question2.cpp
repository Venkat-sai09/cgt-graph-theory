#include <iostream>
#include <vector>

using namespace std;

// Function to check if the graph has an Euler path or circuit
void eulerPath(vector<vector<int>> adjMatrix) {
    int numVertices = adjMatrix.size();
    int oddDegreeVertices = 0;
    vector<int> startVertices;

    // Count the number of vertices with odd degree
    for (int i = 0; i < numVertices; i++) {
        int degree = 0;
        for (int j = 0; j < numVertices; j++) {
            degree += adjMatrix[i][j];
        }
        if (degree % 2 != 0) {
            oddDegreeVertices++;
            startVertices.push_back(i);
        }
    }

    // Check if the graph has an Euler path or circuit
    if (oddDegreeVertices > 2) {
        cout << "No Euler path or circuit exists." << endl;
    } else if (oddDegreeVertices == 2) {
        cout << "Euler path exists." << endl;
        // Find the Euler path
        int startVertex = startVertices[0];
        int currentVertex = startVertex;
        vector<int> path;
        while (true) {
            path.push_back(currentVertex);
            int nextVertex = -1;
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currentVertex][i] == 1) {
                    nextVertex = i;
                    break;
                }
            }
            if (nextVertex == -1) {
                break;
            }
            adjMatrix[currentVertex][nextVertex] = 0;
            adjMatrix[nextVertex][currentVertex] = 0;
            currentVertex = nextVertex;
        }
        // Print the Euler path
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Euler circuit exists." << endl;
        // Find the Euler circuit
        int startVertex = 0;
        int currentVertex = startVertex;
        vector<int> circuit;
        while (true) {
            circuit.push_back(currentVertex);
            int nextVertex = -1;
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currentVertex][i] == 1) {
                    nextVertex = i;
                    break;
                }
            }
            if (nextVertex == -1) {
                break;
            }
            adjMatrix[currentVertex][nextVertex] = 0;
            adjMatrix[nextVertex][currentVertex] = 0;
            currentVertex = nextVertex;
        }
        // Print the Euler circuit
        for (int i = 0; i < circuit.size(); i++) {
            cout << circuit[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    eulerPath(adjMatrix);
    return 0;
}