#ifndef GRAPH_H
#define GRAPH_H

#endif // GRAPH_H

#include <vector>
#include <QPoint>

class Edge
{
public:
    int from;
    int to;
    int weight;
};

/*
class Graph
{
public:
    std::vector<std::vector<Edge>> adj;
    void addVertex()
    {
        adj.push_back({});
    }
    void addEdge(int from, int to, int weight)
    {
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }
};
*/

class Vertex
{
public:
    int id;
    QPointF pos;
};

class Graph
{
public:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

    std::vector<std::vector<Edge>> adj;

    void addVertex(QPointF pos);
    void removeVertex(int id);

    void dfsHelper(int v,
                   std::vector<bool>& visited,
                   std::vector<int>& result);

    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);

    std::vector<int> bfs(int start);
    std::vector<int> dfs(int start);

    std::vector<int> dijkstra(int start);
    std::vector<std::vector<int>> floyd();
};
