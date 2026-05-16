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

void Graph::removeVertex(int id)
{
    if (id < 0 || id >= vertices.size())
    {
        return;
    }

    for (int i = 0; i < adj.size(); i++)
    {
        for (auto it = adj[i].begin();
             it != adj[i].end();)
        {
            if (it->to == id)
            {
                it = adj[i].erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    vertices.erase(vertices.begin() + id);

    adj.erase(adj.begin() + id);

    for (int i = 0; i < vertices.size(); i++)
    {
        vertices[i].id = i;
    }

    for (int i = 0; i < adj.size(); i++)
    {
        for (Edge& e : adj[i])
        {
            if (e.from > id)
            {
                e.from--;
            }

            if (e.to > id)
            {
                e.to--;
            }
        }
    }

    for (auto it = edges.begin();
         it != edges.end();)
    {
        if (it->from == id || it->to == id)
        {
            it = edges.erase(it);
        }
        else
        {
            if (it->from > id)
            {
                it->from--;
            }

            if (it->to > id)
            {
                it->to--;
            }

            ++it;
        }
    }
}

void Graph::addEdge(int from, int to, int weight)
{
    Edge e;

    e.from = from;
    e.to = to;
    e.weight = weight;

    edges.push_back(e);

    adj[from].push_back(e);
}

void Graph::removeEdge(int from, int to)
{
    for (auto it = adj[from].begin();
         it != adj[from].end();)
    {
        if (it->to == to)
        {
            it = adj[from].erase(it);
        }
        else
        {
            ++it;
        }
    }
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

std::vector<int> Graph::dfs(int start)
{
    std::vector<int> result;

    std::vector<bool> visited(vertices.size(), false);

    dfsHelper(start, visited, result);

    return result;
}

std::vector<int> Graph::dijkstra(int start)
{
    int n = vertices.size();

    std::vector<int> dist(n, INT_MAX);

    std::vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int v = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] &&
                (v == -1 || dist[j] < dist[v]))
            {
                v = j;
            }
        }

        if (dist[v] == INT_MAX)
        {
            break;
        }

        visited[v] = true;

        for (Edge e : adj[v])
        {
            int to = e.to;

            int len = e.weight;

            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
            }
        }
    }

    return dist;
}

std::vector<std::vector<int>> Graph::floyd()
{
    int n = vertices.size();

    std::vector<std::vector<int>> dist(
        n,
        std::vector<int>(n, INT_MAX)
        );

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (Edge e : edges)
    {
        dist[e.from][e.to] = e.weight;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX &&
                    dist[k][j] != INT_MAX)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] =
                            dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    return dist;
}
void Graph::updateEdgeWeight(int from,
                             int to,
                             int newWeight)
{
    for (Edge& e : adj[from])
    {
        if (e.to == to)
        {
            e.weight = newWeight;
        }
    }

    for (Edge& e : edges)
    {
        if (e.from == from &&
            e.to == to)
        {
            e.weight = newWeight;
        }
    }
}
