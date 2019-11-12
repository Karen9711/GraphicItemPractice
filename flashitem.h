#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include<QGraphicsItem>
#include<QTimer>
#include<QPainter>
#include<QPen>
class FlashItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void timerEvent(QTimerEvent *event) override;
    QRectF boundingRect() const override;
private:
    QTimer *timer;
    bool flash = false;
public slots:
};

#endif // FLASHITEM_H
