#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int u, int v, bool directed)
    {
        adjList[u].push_back(v);
        if (!directed)
            adjList[v].push_back(u);
    }

    void printAdj()
    {
        for (auto i : adjList)
        {
            cout << i.first << "--> [";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << "]" << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(2, 3, false);
    g.addEdge(2, 0, false);
    g.printAdj();
    return 0;
}