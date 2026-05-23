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
    std::pair<std::vector<int>, int> travellingSalesman(int start);
    std::vector<std::vector<Edge>> adj;

    void addVertex(QPointF pos);
    void removeVertex(int id);

    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);

    void updateEdgeWeight(int from,
                          int to,
                          int newWeight);

    void voyajer();
    void tspHelper(
        int current,
        int start,
        std::vector<bool>& visited,
        std::vector<int>& path,
        int currentCost,
        int& bestCost,
        std::vector<int>& bestPath
        );
};

#endif // GRAPH_H
