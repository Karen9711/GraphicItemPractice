#include "flashitem.h"

FlashItem::FlashItem(QObject *parent) : QObject(parent)
{
    setFlag(ItemIsMovable);
    startTimer(1000);
}

QRectF FlashItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-10-adjust,-10-adjust,43+adjust,43+adjust);
}
void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //绘制阴影
    painter->setPen(Qt::NoPen);         //闪烁图元的阴影区不绘制边线
    painter->setBrush(Qt::darkGray);    //闪烁图元的阴影区的阴影画刷颜色为深灰
    painter->drawEllipse(-7,-7,40,40);

    //闪烁区的椭圆边线颜色为黑色、线宽为0
    painter->setPen(QPen(Qt::black,0));
    painter->setBrush(flash?(Qt::red):(Qt::yellow));	//(a)
    painter->drawEllipse(-10,-10,40,40);
}
void FlashItem::timerEvent(QTimerEvent *event)
{
    flash = !flash;
    update();
}
