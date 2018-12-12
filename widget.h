#ifndef WIDGET_H
#define WIDGET_H
#include"itemmodel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:


    itemmodel *table;
};

#endif // WIDGET_H
