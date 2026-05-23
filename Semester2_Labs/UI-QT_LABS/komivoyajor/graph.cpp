#include "graph.h"

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

void Graph::voyajer(){
    int n = vertices.size();
    std::vector<std::vector<int>> matrix(
        n,
        std::vector<int>(n, INT_MAX)
        );

    for (Edge e : edges)
    {
        matrix[e.from][e.to] = e.weight;
    }

    std::vector<int> Minstb(n);

    for(int i = 0; i < n; i++){
        int temp = INT_MAX;
        for(int k = 0; k < n; k++){
            if(matrix[i][k] < temp){
                temp = matrix[i][k];
            }
        }
        Minstb[i] = temp;
    }
    for(int i = 0; i < n; i++){

        for(int k = 0; k < n; k++){

        }
    }
}
void Graph::tspHelper(
    int current,
    int start,
    std::vector<bool>& visited,
    std::vector<int>& path,
    int currentCost,
    int& bestCost,
    std::vector<int>& bestPath)
{
    // если все вершины посещены
    if (path.size() == vertices.size())
    {
        for (Edge e : adj[current])
        {
            if (e.to == start)
            {
                int totalCost = currentCost + e.weight;

                if (totalCost < bestCost)
                {
                    bestCost = totalCost;

                    bestPath = path;

                    bestPath.push_back(start);
                }
            }
        }

        return;
    }

    for (Edge e : adj[current])
    {
        int next = e.to;

        if (!visited[next])
        {
            visited[next] = true;

            path.push_back(next);

            tspHelper(
                next,
                start,
                visited,
                path,
                currentCost + e.weight,
                bestCost,
                bestPath
                );

            visited[next] = false;

            path.pop_back();
        }
    }
}

std::pair<std::vector<int>, int>
Graph::travellingSalesman(int start)
{
    std::vector<bool> visited(vertices.size(), false);

    std::vector<int> path;

    std::vector<int> bestPath;

    int bestCost = INT_MAX;

    visited[start] = true;

    path.push_back(start);

    tspHelper(
        start,
        start,
        visited,
        path,
        0,
        bestCost,
        bestPath
        );

    return {bestPath, bestCost};
}
