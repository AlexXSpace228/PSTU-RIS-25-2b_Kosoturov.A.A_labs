#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Graph graph;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawGraph();
private slots:
    void mousePressEvent(QMouseEvent *event);
    int clickedVertex(QPointF pos);
    void on_AddEdgeButton_clicked();
    void drawArrow(QGraphicsScene* scene, QPointF p1, QPointF p2);
    void on_Voyajor_clicked();
};

#endif // MAINWINDOW_H
