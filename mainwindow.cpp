#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleOptionGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    x=(this->geometry().height())/3;
    y=(this->geometry().width())/5;
    ui->setupUi(this);
    ui->verticalSlider->setMinimum(60);
    ui->verticalSlider->setMaximum(250);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    Q_UNUSED(widget);
//   // painter->setPen(m_pen);
//    //painter->setBrush(m_brush);
//    QPointF center = this->rect().center();
//    qreal radius = abs(this->rect().right() - this->rect().left())/2.;
//    QPointF newTopLeft(center);
//    newTopLeft.setX(newTopLeft.x() - radius);
//    newTopLeft.setY(newTopLeft.y() - radius);
//    QPointF newBottomRight(center);
//    newBottomRight.setX(newBottomRight.x() + radius);
//    newBottomRight.setY(newBottomRight.y() + radius);

//    QRectF modified(newTopLeft, newBottomRight);
//    QPointF newCenter = mapFromItem(this, center);
//    modified.moveCenter(newCenter);
//    this->setRect(modified);
//    if(m_ellipse && m_fromCenter)
//    {
//        painter->save();
//        painter->drawEllipse(this->rect().center(), radius, radius);
//        painter->restore();
//    }
//    if(m_ellipse)
//    {
//        painter->drawEllipse(this->rect());
//    }
//}

void MainWindow::paintEvent(QPaintEvent *)
{
    QRectF rectangle(x , y , z , z);
    QPainter painter(this);
    painter.drawArc( x , y , z , z ,0,16*360);
    painter.drawEllipse(rectangle);
}



void MainWindow::on_pushButton_clicked()
{
    y -=10;
    update();
}


void MainWindow::on_pushButton_3_clicked()
{
    y += 10;
    update();
}

void MainWindow::on_pushButton_2_clicked()
{
    x -= 10;
    update();
}

void MainWindow::on_pushButton_4_clicked()
{
    x += 10;
    update();
}

void MainWindow::on_verticalSlider_actionTriggered(int action)
{
    z = ui->verticalSlider->value();
//    if(ui->verticalSlider->isSliderDown())
//    {
//       x -= (ui->verticalSlider->value())/75;
//    }

//    else
//    {
//            x -= 100000*(ui->verticalSlider->value());

//    }

    update();
}




