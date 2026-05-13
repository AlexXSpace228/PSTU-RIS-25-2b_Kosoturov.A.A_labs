#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <QPointF>

class Edge
{
public:
    int from;
    int to;
    int weight;
};

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

    void updateEdgeWeight(int from,
                          int to,
                          int newWeight);

    std::vector<int> bfs(int start);
    std::vector<int> dfs(int start);

    std::vector<int> dijkstra(int start);

    std::vector<std::vector<int>> floyd();
};

#endif // GRAPH_H
