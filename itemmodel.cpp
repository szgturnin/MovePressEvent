#include "itemmodel.h"

itemmodel::itemmodel()
{
     m_model=new QStandardItemModel(3,3);
     m_painter=new QPainter(this);
     this->setModel(m_model);//要想QStandardItemModel显示出来，这个函数必须是要调用的
     initModel();
}
void itemmodel::initModel()
{
    for(int row=0;row<3;row++)
    {
        for(int column=0;column<3;column++)
        {
            QStandardItem *item=new QStandardItem(QString::number(row)+","+QString::number(column));
            m_model->setItem(row,column,item);
        }
    }

}

void itemmodel::mouseMoveEvent(QMouseEvent *event)
{
    if(!(event->buttons()&Qt::LeftButton))
        return;
    if((event->pos()-m_position).manhattanLength()<QApplication::startDragDistance())
        return ;
    QPoint nowPoint=event->pos();
    int width=nowPoint.rx()-m_position.rx();
    int height=nowPoint.ry()-m_position.ry();

    QRect rect(m_position.rx(),m_position.ry(),width,height);
   // QPaintEvent paintevent(rect);
  //  paintEvent(&paintevent);
    update(rect);//不要直接调用QPaintEvent,使用update，才对。 如果使用上面的形式，会报错QPainter   Painter not active
   // qDebug()<<"mouseMoveEvent"<<endl;
}

void itemmodel::mousePressEvent(QMouseEvent *event)
{
    flag=1;
    if(event->button()==Qt::LeftButton)
    {
        m_position=event->pos();
    }
    QTableView::mousePressEvent(event);
}

void itemmodel::mouseReleaseEvent(QMouseEvent *event)
{
    //m_painter->eraseRect(this->rect());
    update();//不在这里调用的话，会出现界面未刷新，导致刚刚画的线条依旧存在
    //qDebug()<<"mouseReleaseEvent"<<endl;
}

void itemmodel::paintEvent(QPaintEvent *event)
{
   // QPainter m_painter(this);
    //m_painter.begin(this);
    if(0==flag)
    {
        m_painter->begin(this);//begin和end最好在一起使用
           m_painter->setPen(Qt::DashLine);
           QRect rect=event->rect();
           int top=rect.top();
           int left=rect.left();
           int width=rect.width();
           int height=rect.height();
           QRectF rec(0,0,width,height);
           m_painter->drawRect(rec);
           m_painter->end();
           QWidget::paintEvent(event);
            qDebug()<<"painteventaaaaaaaaaaaaaaaaaaaaa"<<endl;
    }
    else
    {
        m_painter->begin(this);//begin和end最好在一起使用
           m_painter->setPen(Qt::DashLine);
           QRect rect=event->rect();
           int top=rect.top();
           int left=rect.left();
           int width=rect.width();
           int height=rect.height();
           QRectF rec(left,top,width-0.01,height-0.01);
           m_painter->drawRect(rec);
           m_painter->end();
           QTableView::paintEvent(event);
         qDebug()<<"painteventxxxxxxxxxxxxxxxxxx"<<endl;
    }



}

