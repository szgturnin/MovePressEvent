#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(500,800);
    this->setWindowTitle(QString("window_Main"));

   table=new itemmodel();
   QGridLayout *lay=new QGridLayout(this);
   lay->addWidget(table);
   this->setLayout(lay);

}

Widget::~Widget()
{

}



