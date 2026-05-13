#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    scene->addEllipse(100, 100, 50, 50);
    scene->addLine(125, 125,
                   300, 300);
    scene->addText("5")->setPos(200, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
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
            p2.y()
            );
    }

    for (Vertex v : graph.vertices)
    {
        scene->addEllipse(
            v.pos.x() - 20,
            v.pos.y() - 20,
            40,
            40
            );

        scene->addText(QString::number(v.id))
            ->setPos(v.pos.x() - 5,
                     v.pos.y() - 10);
    }
}
*/
