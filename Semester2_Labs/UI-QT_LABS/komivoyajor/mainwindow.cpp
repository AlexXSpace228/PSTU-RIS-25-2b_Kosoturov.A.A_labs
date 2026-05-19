#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsTextItem>
#include <QInputDialog>
#include <QMouseEvent>
#include <QDebug>

bool addEdgeMode = false;
int firstVertex = -1;

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
    /*
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
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawArrow(QGraphicsScene* scene, QPointF p1, QPointF p2)
{
    QLineF line(p1, p2);

    // укоротить линию, чтобы не заходила в вершину
    double arrowPadding = 20;
    if (line.length() > arrowPadding)
        line.setLength(line.length() - arrowPadding);

    QPointF endPoint = line.p2();

    // угол направления
    double angle = std::atan2(-line.dy(), line.dx());

    double arrowSize = 10;

    QPointF arrowP1 = endPoint + QPointF(
                          std::sin(angle - M_PI / 3) * arrowSize,
                          std::cos(angle - M_PI / 3) * arrowSize
                          );

    QPointF arrowP2 = endPoint + QPointF(
                          std::sin(angle - M_PI + M_PI / 3) * arrowSize,
                          std::cos(angle - M_PI + M_PI / 3) * arrowSize
                          );

    // линия ребра
    scene->addLine(line, QPen(Qt::black));

    // стрелка
    scene->addLine(QLineF(endPoint, arrowP1), QPen(Qt::black));
    scene->addLine(QLineF(endPoint, arrowP2), QPen(Qt::black));
}

void MainWindow::drawGraph()
{
    scene->clear();

    for (Edge e : graph.edges)
    {
        QPointF p1 = graph.vertices[e.from].pos;
        QPointF p2 = graph.vertices[e.to].pos;

        drawArrow(scene, p1, p2);

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

int MainWindow::clickedVertex(QPointF pos)
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


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint localPos =
        ui->graphicsView->mapFrom(this,
                                  event->pos());

    if (!ui->graphicsView->rect().contains(localPos))
    {
        return;
    }
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
        bool ok;

        int weight = QInputDialog::getInt(
            this,
            "Вес ребра",
            "Введите вес:",
            1,
            1,
            999,
            1,
            &ok
            );

        if (ok)
        {
            graph.addEdge(
                firstVertex,
                secondVertex,
                weight
                );
        }

        firstVertex = -1;
        addEdgeMode = false;

        drawGraph();
    }
}

void MainWindow::on_AddEdgeButton_clicked()
{
    addEdgeMode = true;
    firstVertex = -1;

    ui->textEdit->append(
        "Выберите первую вершину"
        );
}


void MainWindow::on_Voyajor_clicked()
{

}

