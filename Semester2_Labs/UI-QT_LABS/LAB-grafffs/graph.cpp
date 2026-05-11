#include "graph.h"
#include <queue>
void Graph::addVertex(QPointF pos)
{
    Vertex v;

    v.id = vertices.size();
    v.pos = pos;

    vertices.push_back(v);

    adj.push_back({});
}

void Graph::addEdge(int from, int to, int weight)
{
    Edge e1;
    e1.from = from;
    e1.to = to;
    e1.weight = weight;

    Edge e2;
    e2.from = to;
    e2.to = from;
    e2.weight = weight;

    edges.push_back(e1);

    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

std::vector<int> Graph::bfs(int start)
{
    std::vector<int> result;

    std::vector<bool> visited(vertices.size(), false);

    std::queue<int> q;

    visited[start] = true;

    q.push(start);

    while (!q.empty())
    {
        int v = q.front();

        q.pop();

        result.push_back(v);

        for (Edge e : adj[v])
        {
            int to = e.to;

            if (!visited[to])
            {
                visited[to] = true;

                q.push(to);
            }
        }
    }

    return result;
}

void Graph::dfsHelper(int v,
                      std::vector<bool>& visited,
                      std::vector<int>& result)
{
    visited[v] = true;

    result.push_back(v);

    for (Edge e : adj[v])
    {
        int to = e.to;

        if (!visited[to])
        {
            dfsHelper(to, visited, result);
        }
    }
}

std::vector<int> Graph::dfs(int start)
{
    std::vector<int> result;

    std::vector<bool> visited(vertices.size(), false);

    dfsHelper(start, visited, result);

    return result;
}
