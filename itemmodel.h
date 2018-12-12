#ifndef ITEMMODEL_H
#define ITEMMODEL_H
#include<QStandardItemModel>
#include<QStandardItem>
#include<QTableView>
#include <QWidget>
#include<QMouseEvent>
#include<QString>
#include<QApplication>
#include<QPoint>
#include<QPainter>
#include <QRectF>
#include<QRect>
#include<QDebug>
#include<QPaintEvent>
#include<QPen>

#include<QGridLayout>
#include<QHBoxLayout>
class itemmodel : public QTableView
{
    Q_OBJECT
public:
    itemmodel();
    void initModel();
protected:
    QStandardItemModel *m_model;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    QPoint m_position;
    QPainter *m_painter;
    int flag=0;
};

#endif // ITEMMODEL_H
