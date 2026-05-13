#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsTextItem>

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
            scene->addText(QString::number(v.id));

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

    graph.addVertex(QPointF(100, 100));
    graph.addVertex(QPointF(300, 100));
    graph.addVertex(QPointF(200, 250));

    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 7);
    graph.addEdge(0, 2, 3);

    drawGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}
