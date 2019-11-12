#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenus();
    initScene();
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();
    this->setCentralWidget(view);
    this->resize(550,450);//比scene大一点可以把图元完全显示
    this->setWindowTitle("graphics item");
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
{
    newAct = new QAction(QString::fromLocal8Bit("新建"),this);
    connect(newAct,&QAction::triggered,this,&MainWindow::slotNew);

    clearAct = new QAction(QString::fromLocal8Bit("清除"),this);
    exitAct = new QAction(QString::fromLocal8Bit("退出"),this);
    connect(exitAct,&QAction::triggered,this,[=](){
        this->close();
    });

    addEllipseItemAct = new QAction(QString::fromLocal8Bit("加入 椭圆"),this);
    connect(addEllipseItemAct,&QAction::triggered,this,&MainWindow::slotAddEllipseItem);

    addPolygonItemAct = new QAction(QString::fromLocal8Bit("加入 多边形"),this);
    connect(addPolygonItemAct,&QAction::triggered,this,&MainWindow::slotAddPolygonItem);

    addTextItemAct = new QAction(QString::fromLocal8Bit("加入 文字"),this);
    connect(addTextItemAct,&QAction::triggered,this,&MainWindow::slotAddTextItem);

    addRectItemAct = new QAction(QString::fromLocal8Bit("加入 长方形"),this);
    connect(addRectItemAct,&QAction::triggered,this,&MainWindow::slotAddRectItem);

    addAlphaItemAct = new QAction(QString::fromLocal8Bit("加入 透明图片"),this);
    connect(addAlphaItemAct,&QAction::triggered,this,&MainWindow::slotAddAlphaItem);

    addFlashItemAct = new QAction(QString::fromLocal8Bit("加入 闪烁图片"),this);
    connect(addFlashItemAct,&QAction::triggered,this,&MainWindow::slotAddFlashItem);

    addAnimItemAct = new QAction(QString::fromLocal8Bit("加入 动画图片"),this);
    connect(addAnimItemAct,&QAction::triggered,this,&MainWindow::slotAddAnimationItem);

    QMenu *filemenu = menuBar()->addMenu(QString::fromLocal8Bit("文件"));
    QMenu *editmenu = menuBar()->addMenu(QString::fromLocal8Bit("编辑"));
    filemenu->addAction(newAct);
    filemenu->addAction(clearAct);
    filemenu->addAction(exitAct);

    editmenu->addAction(addEllipseItemAct);
    editmenu->addAction(addPolygonItemAct);
    editmenu->addAction(addTextItemAct);
    editmenu->addAction(addRectItemAct);
    editmenu->addAction(addAlphaItemAct);
    editmenu->addAction(addFlashItemAct);
    editmenu->addAction(addAnimItemAct);
}

void MainWindow::initScene()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    slotClear();
    slotAddRectItem();
    slotAddEllipseItem();
    slotAddTextItem();
    slotAddAlphaItem();
    slotAddPolygonItem();
}

void MainWindow::slotClear()
{
    QList<QGraphicsItem *>  list = scene->items();
    while(!list.empty())
    {
        scene->removeItem(list.at(0));
        list.removeAt(0);
    }
}

void MainWindow::slotNew()
{
    MainWindow *newWindow = new MainWindow;
    newWindow->show();
}
void MainWindow::slotAddEllipseItem()	//在场景中加入一个椭圆形图元
{
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(QRectF(0,0,80, 60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));//随机颜色
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void MainWindow::slotAddRectItem()          //在场景中加入一个长方形图元
{
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0,0, 60,60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setPen(pen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void MainWindow::slotAddTextItem()  		//在场景中加入一个文字图元
{
    QFont font("Times",16);
    QGraphicsTextItem *item = new QGraphicsTextItem("Hello Qt");
    item->setFont(font);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setDefaultTextColor(QColor(qrand()%256,qrand()%256,qrand ()%256));
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void MainWindow::slotAddPolygonItem()  	//在场景中加入一个多边形图元
{
    QVector<QPoint> v;
    v<<QPoint(30,-15)<<QPoint(0,-30)<<QPoint(-30,-15)
            <<QPoint(-30,15)<<QPoint(0,30)<<QPoint(30,15);
    QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void MainWindow::slotAddAlphaItem()
{
    QGraphicsPixmapItem *item =
            scene->addPixmap(QPixmap("image.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void MainWindow::slotAddFlashItem()
{
    FlashItem *item = new FlashItem;
    scene->addItem(item);
    item->setPos(qrand()%int(scene->sceneRect().width())-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddAnimationItem()
{
    StarItem *item = new StarItem;
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *line = new QTimeLine(4000);//duration=4000ms
    line->setCurveShape(QTimeLine::SineCurve);
    line->setLoopCount(0);
    anim->setTimeLine(line);
    int y = (qrand()%400)-200;
    for(int i=0;i<400;i++)
    {
        anim->setPosAt(i/400.0,QPoint(i-200,y));
    }
    line->start();
    scene->addItem(item);


}
