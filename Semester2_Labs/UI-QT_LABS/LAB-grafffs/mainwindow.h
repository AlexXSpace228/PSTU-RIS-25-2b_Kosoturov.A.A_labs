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
    void on_FloydButton_clicked();
    void on_DFSButton_2_clicked();
    void on_DijkstraButton_clicked();
    void on_BFSButton_clicked();
    void onNewPointButtonclicked();
    void mousePressEvent(QMouseEvent *event);
    void onAddEdgeButtonclicked();
};

#endif // MAINWINDOW_H
