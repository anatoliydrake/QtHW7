#include "mainwindow.h"
#include <QGridLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scene = new QGraphicsScene(this);
    setScene(scene);
    bscheme = new Blockscheme(this);
    scene->addItem(bscheme);
    bscheme1 = new Blockscheme(this);
    scene->addItem(bscheme1);
//    setSceneRect(0, 0, 500, 500);

    connect(bscheme, SIGNAL(reDraw()), this, SLOT(reDraw()));
    connect(bscheme1, SIGNAL(reDraw()), this, SLOT(reDraw()));
    connect(bscheme, SIGNAL(dblClick()), this, SLOT(randomColor()));
    connect(bscheme1, SIGNAL(dblClick()), this, SLOT(randomColorAll()));
//    connect(scene, SIGNAL(dblClick()), this, SLOT(addNew()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::viewport()->grabMouse();
    if (event->button() == Qt::LeftButton)
    {
        addNew();
    }
    QGraphicsView::viewport()->releaseMouse();
}

void MainWindow::reDraw()
{
    scene->update();
    update();
}

void MainWindow::randomColor()
{
    bscheme->setBrush(QColor(rand() % 256, rand() % 256, rand() % 256));
}

void MainWindow::randomColorAll()
{
    bscheme->setBrush(QColor(rand() % 256, rand() % 256, rand() % 256));
    bscheme1->setBrush(QColor(rand() % 256, rand() % 256, rand() % 256));
}

void MainWindow::addNew()
{
    Blockscheme* block = new Blockscheme(this);
    block->setPos(0, 0);
    scene->addItem(block);
}

