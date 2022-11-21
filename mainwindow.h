#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "blockscheme.h"
#include <QGraphicsSceneMouseEvent>
//#include <QMainWindow>

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    Blockscheme *bscheme, *bscheme1;

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void reDraw();
    void randomColor();
    void randomColorAll();
    void addNew();
//signals:
//void addNew1();
};
#endif // MAINWINDOW_H
