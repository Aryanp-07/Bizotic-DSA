#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

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

    void BFS(int source)
    {
        queue<int> q;
        int front;
        q.push(source);         //* push source in queue
        visited[source] = true; //* set the source as visited
        while (!q.empty())      //* while the queue has elements
        {
            front = q.front(); //* find the front of the queue
            q.pop();           //* remove the front element

            cout << front << " "; //* print the front element

            for (auto i : adjList[front]) //* for every element in its adjacency list
            {
                if (!visited[i]) //* if the neighbour is not visited
                {
                    q.push(i);         //* push the neighbour into the queue
                    visited[i] = true; //* set the neighbour as visited
                }
            }
        }
    }

    void DFS(int source)
    {
        stack<int> s;
        s.push(source);
        visited[source] = true;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            cout << top << " ";

            for (auto i : adjList[top])
            {
                if (!visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void dfsrecur(int source)
    {
        visited[source] = true;
        cout << source << " ";

        for (auto x : adjList[source])
        {
            if (!visited[x])
                dfsrecur(x);
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
    // g.printAdj();
    // g.BFS(0);
    // g.DFS(0);
    g.dfsrecur(0);
    return 0;
}
