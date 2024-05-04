#include <iostream>
#include <vector>
using namespace std;

class Graph //* using adjacency matrix
{
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printAdj()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printAdj();
    return 0;
}