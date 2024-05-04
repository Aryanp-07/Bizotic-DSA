#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class DSU //* Disjoint Set Union
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int v)
    {
        parent.resize(v, -1);
        rank.resize(v, 0);
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x); //* find parent of s1
        int s2 = find(y); //* find parent of s2

        if (s1 != s2) //* if their parents arent the same
        {
            //* attach smaller tree to bigger one (using ranks - bigger tree has higher rank)
            if (rank[s1] < rank[s2])
                parent[s1] = s2;
            else if (rank[s1] > rank[s2])
                parent[s2] = s1;
            else
            {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};

class Graph
{
    int vertices;
    unordered_map<int, list<pair<int, int>>> adjList;
    vector<vector<int>> edges;

public:
    Graph(int v) : vertices(v) {}

    void addEdge(int u, int weight, int v)
    {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
        edges.push_back({weight, u, v});
    }

    void kruskal(int source)
    {
        sort(edges.begin(), edges.end());
        DSU dsu(vertices);
        int sum = 0;

        for (auto edge : edges)
        {
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (dsu.find(u) != dsu.find(v)) //* if it does not create cycle, add to MST
            {
                dsu.unite(u, v);
                sum += w;
                cout << u << " -- " << v << " == " << w << endl;
            }
        }

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
    cout << endl;
    g.kruskal(0);
    return 0;
}
