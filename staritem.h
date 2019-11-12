#ifndef STARITEM_H
#define STARITEM_H

#include <QObject>
#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
class StarItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit StarItem(QObject *parent = nullptr);
    QPixmap pix;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
signals:

public slots:
};

#endif // STARITEM_H
