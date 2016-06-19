#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
    turn=0;
    b=0;
    score=0;
    q_button= new QPushButton("END",this);
    q_button->setGeometry(QRect(QPoint(0,0),QSize(50,50)));
    connect(q_button, SIGNAL(released()),this,SLOT(Quit()));
    n_button= new QPushButton("restart",this);
    n_button->setGeometry(QRect(QPoint(0,50),QSize(50,50)));
    connect(n_button, SIGNAL(released()),this,SLOT(New()));
    text = new QTextEdit(this);
    text->setPlainText(QString("Score:"+QString::number(score)));
    text->setFont(QFont("Arial",5));
    text->cursorForPosition(QPoint(0,100));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));


    randlist.push_back(1);
    randlist.push_back(2);
    randlist.push_back(3);
    randlist.push_back(4);
    randlist.push_back(5);
    randlist.push_back(6);
    randlist.push_back(7);
    randlist.push_back(8);
    randlist.push_back(9);
    randlist.push_back(10);
    randlist.push_back(11);
    randlist.push_back(12);
    for(int i=0;i<12;i++)
    {
        if(randlist[i]==1)
        {

           birdie1=new Bird(0.0f,4.0f,1.0f,&timer,QPixmap(":/bird.png").scaled(height()/6.0,height()/6.0),world,scene);
           birdie1->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie1);
        }
        else if(randlist[i]==2)
        {

           birdie2=new bird2(3.0f,4.0f,1.0f,&timer,QPixmap(":/image/angry-bird-clip-art-angry-birds-space-orange-bird.png").scaled(height()/6.0,height()/6.0),world,scene);
           birdie2->many();
           birdlist.push_back(birdie2);

        }



        else if(randlist[i]==3)
        {

           birdie3=new Bird(0.0f,4.0f,2.0f,&timer,QPixmap(":/image/ABMovie_Bomb_Flying.png").scaled(height()/2.0,height()/2.0),world,scene);
           birdie3->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie3);
        }
        else if(randlist[i]==4)
        {

           birdie4=new Bird(0.0f,4.0f,1.0f,&timer,QPixmap(":/image/images (1)651.png").scaled(height()/6.0,height()/6.0),world,scene);
           birdie4->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie4);
        }
        else if(randlist[i]==5)
        {

           birdie5=new Bird(100.0f,100.0f,0.0f,&timer,QPixmap(":/image/778654.png").scaled(height()/100.0,height()/100.0),world,scene);
           birdie5->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie5);
        }
        else if(randlist[i]==6)
        {

            stone1 = new Bird(17.0f,8.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone1->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone1);
        }
        else if(randlist[i]==7)
        {

            stone2 = new Bird(17.0f,10.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone2->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone2);
        }
        else if(randlist[i]==8)
        {

            stone3 = new Bird(17.0f,12.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone3->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone3);
        }
        else if(randlist[i]==9)
        {

            stone4 = new Bird(27.0f,8.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone4->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone4);
        }
        else if(randlist[i]==10)
        {

            stone5 = new Bird(27.0f,10.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone5->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone5);
        }
        else if(randlist[i]==11)
        {

            stone6 = new Bird(27.0f,12.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone6->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone6);
        }
        else if(randlist[i]==12)
        {

            pigdie = new Bird(22.0f,10.0f,1.0f,&timer,QPixmap(":/image/1450160510324.png").scaled(height()/6.0,height()/6.0),world,scene);
            pigdie->setLinearVelocity(b2Vec2(0,0));

           birdlist.push_back(pigdie);
        }


    }


    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(turn==0)
        {

        std::cout << "Press !" << std::endl ;
        turn=1;
        }
        }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */

        if(turn==1)
        {
            QMouseEvent *me=dynamic_cast<QMouseEvent *>(event);
            pt.setX((me->pos().x()) * GameItem::g_windowsize.width()/9/GameItem::g_windowsize.width()/9);
            pt.setY((1.0f-(me->pos().y())/GameItem::g_windowsize.height()) * GameItem::g_worldsize.height());
            birdlist[b]->g_body->SetActive(false);
            birdlist[b]->g_body->SetTransform(b2Vec2(pt.x(),pt.y()),0);
            std::cout << "Move !" << std::endl ;
            turn=2;
        }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        std::cout << "Release !" << std::endl ;
        if(turn==2)
        {
            scoretimer=new QTimer(this);
            connect(scoretimer,SIGNAL(timeout()),this,SLOT(Score()));
            scoretimer->start(100);
            int xn=sqrt((100-pt.x()*pt.x()));
            int yn=sqrt((100-pt.y()*pt.y()));
            birdlist[b]->g_body->SetActive(true);

           if(b==1)
               {birdlist[b]->setLinearVelocity(b2Vec2(10*xn,10*yn));}
           if(b==3)
           {birdlist[b]->setLinearVelocity(b2Vec2(0,0));}

           else if(b!=1&&b!=3&&b!=4)
            {birdlist[b]->setLinearVelocity(b2Vec2(4*xn/3,4*yn/3));}
std::cout<<b<<std::endl;
std::cout<<turn<<std::endl;
            b=b+1;




        turn=0;
        }
    }

    return false;
}

void MainWindow::New()
{
    delete birdie1;
    delete birdie2;
    delete birdie3;
    delete birdie4;\
    delete birdie5;
    delete pigdie;
    delete stone1;
    delete stone2;
    delete stone3;
    delete stone4;
     delete stone5;
     delete stone6;

    itemList.clear();
    int i=0;
    turn=0;
    b=0;
    randlist.push_back(1);
    randlist.push_back(2);
    randlist.push_back(3);
    randlist.push_back(4);
    randlist.push_back(5);
    randlist.push_back(6);
    randlist.push_back(7);
    randlist.push_back(8);
    randlist.push_back(9);
    randlist.push_back(10);
    randlist.push_back(11);
    randlist.push_back(12);
    for(i=0;i<12;i++)
    {
        if(randlist[i]==1)
        {

           birdie1=new Bird(0.0f,4.0f,1.0f,&timer,QPixmap(":/bird.png").scaled(height()/6.0,height()/6.0),world,scene);
           birdie1->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie1);
        }
        else if(randlist[i]==2)
        {

           birdie2=new bird2(3.0f,4.0f,1.0f,&timer,QPixmap(":/image/angry-bird-clip-art-angry-birds-space-orange-bird.png").scaled(height()/6.0,height()/6.0),world,scene);
           birdie2->many();
           birdlist.push_back(birdie2);

        }



        else if(randlist[i]==3)
        {

           birdie3=new Bird(0.0f,4.0f,2.0f,&timer,QPixmap(":/image/ABMovie_Bomb_Flying.png").scaled(height()/2.0,height()/2.0),world,scene);
           birdie3->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie3);
        }
        else if(randlist[i]==4)
        {

           birdie4=new Bird(0.0f,4.0f,1.0f,&timer,QPixmap(":/image/images (1)651.png").scaled(height()/6.0,height()/6.0),world,scene);
           birdie4->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie4);
        }
        else if(randlist[i]==5)
        {

           birdie5=new Bird(100.0f,100.0f,0.0f,&timer,QPixmap(":/image/778654.png").scaled(height()/100.0,height()/100.0),world,scene);
           birdie5->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(birdie5);
        }
        else if(randlist[i]==6)
        {

            stone1 = new Bird(17.0f,8.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone1->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone1);
        }
        else if(randlist[i]==7)
        {

            stone2 = new Bird(17.0f,10.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone2->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone2);
        }
        else if(randlist[i]==8)
        {

            stone3 = new Bird(17.0f,12.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone3->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone3);
        }
        else if(randlist[i]==9)
        {

            stone4 = new Bird(27.0f,8.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone4->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone4);
        }
        else if(randlist[i]==10)
        {

            stone5 = new Bird(27.0f,10.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone5->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone5);
        }
        else if(randlist[i]==11)
        {

            stone6 = new Bird(27.0f,12.0f,1.0f,&timer,QPixmap(":/image/stone.png").scaled(height()/4.0,height()/4.0),world,scene);
            stone6->setLinearVelocity(b2Vec2(0,0));
           birdlist.push_back(stone6);
        }
        else if(randlist[i]==12)
        {

            pigdie = new Bird(22.0f,10.0f,1.0f,&timer,QPixmap(":/image/1450160510324.png").scaled(height()/6.0,height()/6.0),world,scene);
            pigdie->setLinearVelocity(b2Vec2(0,0));

           birdlist.push_back(pigdie);
        }


    }


    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}


void MainWindow::Quit()
{
    emit quitGame();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    exit(0);
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::Score()
{
    if (pigdie->g_body->GetLinearVelocity().x!=0||pigdie->g_body->GetLinearVelocity().y!=0)
    {score=score+1;
    text->setPlainText(QString("Score:"+QString::number(score)));}

}
