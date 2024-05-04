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
    vector<int> dist;

public:
    Graph(int v)
    {
        vertices = v;
        dist.resize(vertices, INT_MAX);
    }

    void addEdge(int u, int weight, int v)
    {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    vector<int> dijkstras(int source)
    {
        //* priority_queue<type,container,functer> - to convert to min-heap from max-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[source] = 0;
        pq.push({0, source});
        while (!pq.empty())
        {
            int curr_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (curr_dist > dist[u])
                continue;

            for (auto neighbor : adjList[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
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

    vector<int> distance = g.dijkstras(0);
    for (auto x : distance)
        cout << x << " ";
    cout << endl;

    return 0;
}