#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QDebug>

bool addEdgeMode = false;
int firstVertex = -1;

/*
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
    graph.addVertex(scenePos);
    drawGraph();
}
*/

void MainWindow::drawGraph()
{
    scene->clear();

    for (Edge e : graph.edges)
    {
        QPointF p1 = graph.vertices[e.from].pos;
        QPointF p2 = graph.vertices[e.to].pos;

        scene->addLine(
            p1.x(),
            p1.y(),
            p2.x(),
            p2.y(),
            QPen(Qt::black)
            );

        QPointF mid(
            (p1.x() + p2.x()) / 2,
            (p1.y() + p2.y()) / 2
            );

        QGraphicsTextItem* weightText =
            scene->addText(QString::number(e.weight));

        weightText->setDefaultTextColor(Qt::black);

        weightText->setPos(mid);
    }

    for (Vertex v : graph.vertices)
    {
        scene->addEllipse(
            v.pos.x() - 20,
            v.pos.y() - 20,
            40,
            40,
            QPen(Qt::black),
            QBrush(Qt::cyan)
            );

        QGraphicsTextItem* text =
            scene->addText(QString::number(v.id+1));

        text->setDefaultTextColor(Qt::black);

        text->setPos(
            v.pos.x() - 5,
            v.pos.y() - 10
            );
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setBackgroundBrush(Qt::white);

    ui->graphicsView->setMouseTracking(true);

    //отрисовка графа из лабы - 19 вар
    graph.addVertex(QPointF(300, 300)); //1
    graph.addVertex(QPointF(125, 50));  //2
    graph.addVertex(QPointF(325, 200));  //3
    graph.addVertex(QPointF(15, 190));  //4
    graph.addVertex(QPointF(360, 60)); //5
    graph.addVertex(QPointF(0, 400)); //6

    graph.addEdge(1-1, 4-1, 15);
    graph.addEdge(1-1, 3-1, 13);
    graph.addEdge(2-1, 1-1, 28);
    graph.addEdge(2-1, 4-1, 20);
    graph.addEdge(3-1, 5-1, 30);
    graph.addEdge(4-1, 6-1, 31);
    graph.addEdge(4-1, 5-1, 39);
    graph.addEdge(5-1, 2-1, 21);
    graph.addEdge(6-1, 1-1, 18);

    drawGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
int clickedVertex(QPointF pos)
{
    for (int i = 0; i < graph.vertices.size(); i++)
    {
        QPointF p = graph.vertices[i].pos;

        double dx = p.x() - pos.x();
        double dy = p.y() - pos.y();

        if (dx*dx + dy*dy < 400) // радиус ~20px
            return i;
    }

    return -1;
}
*/

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint localPos = ui->graphicsView->mapFrom(this, event->pos());
    QPointF scenePos = ui->graphicsView->mapToScene(localPos);

    if (!addEdgeMode)
    {
        graph.addVertex(scenePos);
        drawGraph();
        return;
    }
    int v = clickedVertex(scenePos);

    if (v == -1) return;

    if (firstVertex == -1)
    {
        firstVertex = v;
    }
    else
    {
        int secondVertex = v;

        // пример веса = 1 (позже можно через input dialog)
        graph.addEdge(firstVertex, secondVertex, 1);

        firstVertex = -1;
        addEdgeMode = false;

        drawGraph();
    }
}

void MainWindow::on_FloydButton_clicked()
{
    qDebug() << "clicked";
    ui->textEdit->clear();

    auto dist = graph.floyd();

    ui->textEdit->append("Алгоритм Флойда:");

    for (int i = 0; i < dist.size(); i++)
    {
        QString line;

        for (int j = 0; j < dist[i].size(); j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                line += "INF ";
            }
            else
            {
                line += QString::number(dist[i][j]) + " ";
            }
        }

        ui->textEdit->append(line);
    }
}

void MainWindow::on_DFSButton_2_clicked()
{
    qDebug() << "clicked";
    ui->textEdit->clear();

    std::vector<int> result = graph.dfs(4);

    QString line = "DFS: ";

    for (int v : result)
    {
        line += QString::number(v + 1) + " ";
    }

    ui->textEdit->append(line);
}


void MainWindow::on_DijkstraButton_clicked()
{
    qDebug() << "clicked";
    ui->textEdit->clear();

    std::vector<int> dist = graph.dijkstra(4);

    ui->textEdit->append("Дейкстра от вершины 5:");

    for (int i = 0; i < dist.size(); i++)
    {
        QString line;

        line += "До вершины ";
        line += QString::number(i + 1);
        line += ": ";

        if (dist[i] == INT_MAX)
        {
            line += "INF";
        }
        else
        {
            line += QString::number(dist[i]);
        }

        ui->textEdit->append(line);
    }
}

void MainWindow::on_BFSButton_clicked()
{
    qDebug() << "clicked";
    ui->textEdit->clear();

    std::vector<int> result = graph.bfs(4);

    QString line = "BFS: ";

    for (int v : result)
    {
        line += QString::number(v + 1) + " ";
    }

    ui->textEdit->append(line);
}

void MainWindow::onAddEdgeButtonclicked()
{

}

