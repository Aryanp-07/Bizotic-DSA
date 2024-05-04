#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    unordered_map<int, list<pair<int, int>>> adjList;

public:
    Graph(int v)
    {
        vertices = v;
    }

    void addEdge(int u, int weight, int v)
    {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void prims(int source)
    {
        //* priority_queue<type,container,functer> - to convert to min-heap from max-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create a vector for keys and initialize all keys as infinite (INF)
        vector<int> minWeight(vertices, INT_MAX);

        // To store parent array which in turn store MST
        vector<int> parent(vertices, -1);

        // To keep track of vertices included in MST
        vector<bool> inMST(vertices, false);

        // Insert source itself in priority queue and initialize its key as 0.
        pq.push({0, source});
        minWeight[source] = 0;
        int sum = 0;

        /* Looping till priority queue becomes empty */
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u] == true)
                continue;

            inMST[u] = true; // Include vertex in MST

            // 'i' is used to get all adjacent vertices of a vertex
            for (auto neighbour : adjList[u])
            {
                // Get vertex label and weight of current adjacent of u.
                int v = neighbour.first;
                int weight = neighbour.second;
                //  If v is not in MST and weight of (u,v) is smaller than current key of v
                if (inMST[v] == false && minWeight[v] > weight)
                {
                    if (minWeight[v] != INT_MAX)
                        sum -= minWeight[v];
                    // Updating key of v
                    minWeight[v] = weight;
                    sum += weight;
                    pq.push({minWeight[v], v});
                    parent[v] = u;
                }
            }
        }

        // Print edges of MST using parent array
        for (int i = 1; i < vertices; i++)
            printf("%d <-> %d\n", parent[i], i);

        cout << "SUM = " << sum << endl;
    }
};

int main()
{
    int vertices, edges, m, n, weight;
    cin >> vertices >> edges;

    Graph g(vertices);
    for (int i = 0; i < edges; i++)
    {
        cin >> m >> n >> weight;
        g.addEdge(m, weight, n);
    }

    g.prims(0);
    return 0;
}

// 5 14
// 0 1 2
// 0 2 6
// 1 0 2
// 1 2 3
// 1 3 8
// 1 4 5
// 2 1 3
// 2 4 7
// 3 0 6
// 3 1 8
// 3 4 9
// 4 1 5
// 4 2 7
// 4 3 9
