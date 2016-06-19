#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QKeyEvent>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <bird2.h>
#include <speed.h>
#include <QPushButton>
#include <QTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);


   Bird *birdie1;
   Bird *birdie2;
   Bird *birdie3;
   Bird *birdie4;
   Bird *birdie5;
   Bird *pigdie;
   Bird *stone1;
   Bird *stone2;
   Bird *stone3;
   Bird *stone4;
   Bird *stone5;
   Bird *stone6;
   QPointF pt;
   int b;
   int turn;
   int score;
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void New();
    void Quit();
    void Score();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<int>randlist;
    QList<Bird *>birdlist;
    QList<GameItem *> itemList;
    QTimer timer;
    QTimer *scoretimer;
    QPushButton *q_button;
    QPushButton *n_button;
    QTextEdit *text;

    static QSizeF g_worldsize,g_windowsize;

};

#endif // MAINWINDOW_H
