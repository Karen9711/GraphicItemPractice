#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QAction>
#include<QMenu>
#include<QMenuBar>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsEllipseItem>
#include<QGraphicsRectItem>
#include<QGraphicsItemAnimation>
#include<QTimeLine>
#include"flashitem.h"
#include"staritem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void initScene();
public slots:
    void slotNew();              			//新建一个显示窗体
    void slotClear();           			//清除场景中所有的图元
    void slotAddEllipseItem();              //在场景中加入一个椭圆形图元
    void slotAddPolygonItem();      		//在场景中加入一个多边形图元
    void slotAddTextItem();         		//在场景中加入一个文字图元
    void slotAddRectItem();         		//在场景中加入一个长方形图元
    void slotAddAlphaItem();        		//在场景中加入一个透明蝴蝶图片
    void slotAddFlashItem();              //在场景中加入闪动图元
    void slotAddAnimationItem();
private:
    QGraphicsScene *scene;
    QAction *newAct;
    QAction *clearAct;
    QAction *exitAct;
    QAction *addEllipseItemAct;
    QAction *addPolygonItemAct;
    QAction *addTextItemAct;
    QAction *addRectItemAct;
    QAction *addAlphaItemAct;
    QAction *addFlashItemAct;
    QAction *addAnimItemAct;

};
#endif // MAINWINDOW_H
