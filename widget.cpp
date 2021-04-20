#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    status1 = -1;
    status2 = -1;
    mainScene = new QGraphicsScene;
    mainPixmapItem = new QGraphicsPixmapItem();
    mainScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
    ui->graphicsView->setScene(mainScene);
    //一级槽函数

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_file_btn_clicked()
{

    if(this->status1 == -1)
    {
        ui->m2->setCurrentIndex(1);//翻页操作
        this->status1 += 1;
    }
    else
    {
        ui->m2->setCurrentIndex(0);//返回初始页
        this->status1 = -1;
    }
    qDebug()<<"status1 = "<<this->status1;
}

void Widget::on_pro_btn_clicked()
{
    if(this->status1 == -1)
    {
        ui->m2->setCurrentIndex(2);//翻页操作
        this->status1 += 1;
    }
    else
    {
        ui->m2->setCurrentIndex(0);//返回初始页
        this->status1 = -1;
    }
}

void Widget::on_seg_btn_clicked()
{
/*
 *   cv::Mat dst;
    net.saliency_detection(mimage,dst);
    QImage cur;
    cur = QImage((uchar*)dst.data, dst.cols, dst.rows, QImage::Format_RGBA8888);

    QPixmap out;
    out = QPixmap::fromImage(cur);
    mainScene->clear();
    ui->graphicsView->resetTransform();
    qDebug() << 0;
    mainPixmapItem = mainScene->addPixmap(out);
    qDebug() << 1;
    mainScene->setSceneRect(QRectF(out.rect()));
    qDebug() << 2;
*/
}

void Widget::on_set_btn_clicked()
{
    if(this->status2 == -1)
    {
        ui->m4->setCurrentIndex(2);//翻页操作
        this->status2 += 1;
    }
    else
    {
        ui->m4->setCurrentIndex(0);//返回初始页
        this->status2 = -1;
    }
}

void Widget::on_tool_btn_clicked()
{
    if(this->status2 == -1)
    {
        ui->m4->setCurrentIndex(1);//翻页操作
        this->status2 += 1;
    }
    else
    {
        ui->m4->setCurrentIndex(0);//返回初始页
        this->status2 = -1;
    }
}

void Widget::on_before_btn_clicked()
{
    if(this->status2 == -1)
    {
        ui->m4->setCurrentIndex(3);//翻页操作
        this->status2 += 1;
    }
    else
    {
        ui->m4->setCurrentIndex(0);//返回初始页
        this->status2 = -1;
    }
}

void Widget::on_post_btn_clicked()
{
    if(this->status2 == -1)
    {
        ui->m4->setCurrentIndex(4);//翻页操作
        this->status2 += 1;
    }
    else
    {
        ui->m4->setCurrentIndex(0);//返回初始页
        this->status2 = -1;
    }
}

void Widget::on_tconfirm_btn_clicked()
{
    ui->m4->setCurrentIndex(0);//返回初始页
    this->status2 = -1;
}

void Widget::on_tcancel_btn_clicked()
{
    ui->m4->setCurrentIndex(0);//返回初始页
    this->status2 = -1;
}

void Widget::on_sconfirm_btn_clicked()
{
    ui->m4->setCurrentIndex(0);//返回初始页
    this->status2 = -1;
}

void Widget::on_scancel_btn_clicked()
{
    ui->m4->setCurrentIndex(0);//返回初始页
    this->status2 = -1;
}

void Widget::on_about_btn_clicked()
{

}

void Widget::on_open_btn_clicked()
{
    QString imagePath;
    imagePath = QFileDialog::getOpenFileName(this);
    mimage =cv::imread(imagePath.toLocal8Bit().data());
    qDebug()<<imagePath;
    //mimage =;
    QPixmap mainPixmap(imagePath);
    mainPixmapItem = mainScene->addPixmap(mainPixmap);
    mainScene->setSceneRect(QRectF(mainPixmap.rect()));
    //返回初始页
    ui->m2->setCurrentIndex(0);
}

void Widget::on_save_btn_clicked()
{
    QString fileName = QCoreApplication::applicationDirPath();
    qDebug()<<fileName;
    QString savePath = "./";
    QString idx =  QString::number(qrand())+QString(".jpg");
    QString path = savePath+idx;
    qDebug()<<"save_path is "<<path;
    if (!savePath.isEmpty()) {

        QString file(savePath+idx);

        //Save image to new path
        bool re = mainPixmapItem->pixmap().save(file);
        if(re)
            QMessageBox::information(this,"保存","保存成功!");
        else
            QMessageBox::information(this,"保存","保存失败!");
    }
}

void Widget::on_saveas_btn_clicked()
{
    QString newpath = QFileDialog::getSaveFileName(this, tr("Save image"), QString(),
               tr("All files (*);;"
                  "Image BPM (*.bpm);;"
                  "Image GIF (*.gif);;"
                  "Image JPG (*.jpg);;"
                  "Image JPEG (*.jpeg);;"
                  "Image PNG (*.png);;"
                  "Image PPM (*.ppm);;"
                  "Image XBM (*.xbm);;"
                  "Image XPM (*.xpm);;"));

       if (!newpath.isEmpty())
       {
           qDebug()<<"save_path is "<<newpath;
           bool re = mainPixmapItem->pixmap().save(newpath);
           if(re)
               QMessageBox::information(this,"保存","保存成功!");
           else
               QMessageBox::information(this,"保存","保存失败!");
        }
}
