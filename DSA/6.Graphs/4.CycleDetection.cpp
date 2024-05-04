#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
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

    void detectCycleBFS(int source)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        int front;
        q.push(source);
        visited[source] = true;
        parent[source] = -1;
        while (!q.empty())
        {
            front = q.front();
            q.pop();

            for (auto i : adjList[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
                else if (parent[front] != i)
                {
                    cout << "Cycle detected" << endl;
                    return;
                }
            }
        }
    }

    bool check(int parent, int current)
    {
        if (adjList[current].empty())
            return false;
        for (auto x : adjList[current])
        {
            if (x == parent)
                return true;
        }
        return false;
    }

    void detectCycleDFS(int source)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        stack<int> s;
        s.push(source);
        visited[source] = true;
        parent[source] = -1;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            for (auto i : adjList[top])
            {
                if (!visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                    parent[i] = top;
                }
                else if (parent[top] != i && check(parent[top], i))
                {
                    cout << "Cycle detected" << endl;
                    return;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    int vertices, edges, m, n;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++)
    {
        cin >> m >> n;
        g.addEdge(m, n, true);
    }
    // g.detectCycleBFS(0);
    g.detectCycleDFS(1);

    return 0;
}

// 6 6
// 0 1
// 1 2
// 1 3
// 2 4
// 3 4
// 4 5

// 8 8
// 0 1
// 1 2
// 1 4
// 2 3
// 4 5
// 5 6
// 3 6
// 6 7

// 8 9
// 1 2
// 2 3
// 3 7
// 3 8
// 8 7
// 2 4
// 4 5
// 5 6
// 6 4

// 5 5
// 1 2
// 2 3
// 3 4
// 3 5
// 5 4