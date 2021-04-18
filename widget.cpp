#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->status = -1;//表示没有一级菜单被按下
    this->status2 = -1;
    this->setWindowTitle("分割软件");

    int x = this->x();
    int y = this->y();
    int x1 = this->geometry().x();
    int y1 = this->geometry().y();
    qDebug()<<"x = "<<x<<" y="<<y;
    qDebug()<<"x1 = "<<x1<<" y1="<<y1;


    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    // 变量
    mainScene = new QGraphicsScene;
    mainPixmapItem = new QGraphicsPixmapItem();
    mainScene->setBackgroundBrush(QColor::fromRgb(224,224,224));
    ui->graphicsView->setScene(mainScene);

    int width1 = this->width();
    int height1 = this->height();
    qDebug()<<"width = "<<width<<" height="<<height;
    qDebug()<<"width1 = "<<width1<<" height1="<<height1;

    //一级菜单信息
    ui->m_1->move(0,0);
    int m1_w = ui->m_1->width();
    int m1_h = ui->m_1->height();
    int x2 = ui->m_1->x();
    int y2 = ui->m_1->y();
    qDebug()<<"m1_x = "<<x2<<" m1_y = "<<y2;
    qDebug()<<"m1_width = "<<m1_w<<" m1_height="<<m1_h;
    //布局
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addLayout(ui->mlayout);
    this->setLayout(mainLayout);
    //二级菜单信息
    //ui->m_2->setFixedSize(182,980);
    //ui->m_2->->setGeometry(QRectF(94,0,182,980));
    ui->m_2->setStyleSheet("QWidget{background-color:rgb(234,234,234)}");

 /*
  * 一级菜单槽函数
 */
    connect(ui->file_btn,&QPushButton::clicked,this,&Widget::file_switchPage);
    connect(ui->seg_btn,&QPushButton::clicked,this,&Widget::seg_switchPage);
    connect(ui->process_btn,&QPushButton::clicked,this,&Widget::process_switchPage);
    connect(ui->tool_btn,&QPushButton::clicked,this,&Widget::toolset_switchPage);
    connect(ui->set_btn,&QPushButton::clicked,this,&Widget::subset_switchPage);

/*
*   二级菜单槽函数
*/
    connect(ui->pre_btn,&QPushButton::clicked,this,&Widget::pre_switchPage);
    connect(ui->last_btn,&QPushButton::clicked,this,&Widget::last_switchPage);
}
void Widget::subset_switchPage()
{
    if(this->status2 == -1)
    {
        ui->m_3->setCurrentIndex(3);//翻页操作
        this->status += 1;
    }
   //应该在2界面加一个关闭按钮，关闭后status变成-1
}
void Widget::toolset_switchPage()
{
    if(this->status2 == -1)
    {
        ui->m_3->setCurrentIndex(4);//翻页操作
        this->status += 1;
    }
   //应该在2界面加一个关闭按钮，关闭后status变成-1
}
void Widget::last_switchPage()
{
    if(this->status2 == -1)
    {
        ui->m_3->setCurrentIndex(2);//翻页操作
        this->status += 1;
    }
   //应该在2界面加一个关闭按钮，关闭后status变成-1
}
void Widget::pre_switchPage()
{
    if(this->status2 == -1)
    {
        ui->m_3->setCurrentIndex(1);//翻页操作
        this->status += 1;
    }
   //应该在1界面加一个关闭按钮，关闭后status变成-1
}
void Widget::file_switchPage()
{
    if(this->status == -1)
    {
        ui->m_2->setCurrentIndex(1);//翻页操作
        this->status += 1;
    }
    else
    {
        ui->m_2->setCurrentIndex(0);//返回初始页
        this->status = -1;
    }
}
void Widget::seg_switchPage()
{
    if(this->status == -1)
    {
        //ui->m_2->setCurrentIndex(2);//翻页操作
        this->status += 1;
    }
    else
    {
        ui->m_2->setCurrentIndex(0);//返回初始页
        this->status = -1;
    }
}
void Widget::process_switchPage()
{
    if(this->status == -1)
    {
        ui->m_2->setCurrentIndex(3);//翻页操作
        this->status += 1;
    }
    else
    {
        ui->m_2->setCurrentIndex(0);//返回初始页
        this->status = -1;
    }
}
void Widget::tool_switchPage()
{
    if(this->status == -1)
    {
        ui->m_2->setCurrentIndex(4);//翻页操作
        this->status += 1;
    }
    else
    {
        ui->m_2->setCurrentIndex(0);//返回初始页
        this->status = -1;
    }
}
void Widget::set_switchPage()
{
    if(this->status == -1)
    {
        ui->m_2->setCurrentIndex(5);//翻页操作
        this->status += 1;
    }
    else
    {
        ui->m_2->setCurrentIndex(0);//返回初始页
        this->status = -1;
    }
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_file_btn_clicked()
{
    // open image


}

/*
 * 二级菜单 -> 打开
*/
void Widget::on_open_btn_clicked()
{
    QString imagePath;
    imagePath = QFileDialog::getOpenFileName(this);
    qDebug()<<imagePath;
    QPixmap mainPixmap(imagePath);
    mainPixmapItem = mainScene->addPixmap(mainPixmap);
    mainScene->setSceneRect(QRectF(mainPixmap.rect()));
    //返回初始页
    ui->m_2->setCurrentIndex(0);
}
/*
    二级菜单 -> 保存
*/
void Widget::on_save_btn_clicked()
{
    QString savePath = "D:/QtCode/SegApp/savedata/";
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
/*
    二级菜单 -> 另存为
*/
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
