ff/*************************************************************************
    > File Name: main.cpp
    > Created Time: 2017年01月20日 星期五 21时38分07秒


 ************************************************************************/
 #include <QGraphicsView>
 #include <QPen>
 #include <QGraphicsScene>
 #include <QApplication>
 #include <QTimer>
 #include <QBrush>
 #include <QGraphicsRectItem>
 #include <QPixmap>
 #include <QDebug>
QGraphicsScene *scene ;
QGraphicsRectItem *rect; 
 void advance(){
     //scene->removeItem(rect);
     rect->setX(int(rect->x()+10)%200);
     //scene->addItem(rect);

 }
 void print(){
     qDebug()<<scene->hasFocus();
 }
 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
    scene = new QGraphicsScene;
     scene->setSceneRect(0, 0, 200, 300);
    rect  = new QGraphicsRectItem(20, 20, 10, 10);
     rect->setBrush(Qt::black);
     QPixmap bg(10, 10);
     QPainter painter(&bg);
     painter.setPen(Qt::red);
     painter.setBrush(Qt::gray);
     painter.drawRect(0, 0, 10, 10);
     QBrush brush(bg);
     scene->setBackgroundBrush(brush);
     
     scene->addItem(rect);
     scene->setFocusItem(rect);
     scene->addRect(0, 0, 10, 200,QPen(Qt::yellow), QBrush(Qt::yellow));
     scene->addRect(0, 0, 200, 10,QPen(Qt::yellow), QBrush(Qt::yellow));
     scene->addRect(190, 0, 10, 200,QPen(Qt::yellow), QBrush(Qt::yellow));
     scene->addRect(0, 190, 200, 10,QPen(Qt::yellow), QBrush(Qt::yellow));

     QGraphicsView *view = new QGraphicsView(scene);
     QTimer timer;
     QObject::connect(&timer, &QTimer::timeout, &advance);
     timer.start(100);
     //QObject::connect(&timer, &QTime::second)
     view->setWindowTitle("line");
     view->show();
     QGraphicsView *view1 = new QGraphicsView(scene);
     view1->setWindowTitle("view1");
     view1->show();
     print();
     return app.exec();
 }
