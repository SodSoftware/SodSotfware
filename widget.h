#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QIODevice>
#include <QMessageBox>
#include "graphicsview.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //变量
    QGraphicsScene  *mainScene;
    QGraphicsPixmapItem *mainPixmapItem;
    /*初始空白页--0
     * 文件页--1
     * 分割页--
     * 处理页--
     * 工具页--
     * 设置页--
     *
     * */

    int status;  //标志位->左侧菜单栏状态
    int status2; //标志位->右侧功能栏状态
private slots:
    void on_file_btn_clicked();

    void on_open_btn_clicked();

    void on_save_btn_clicked();

    void on_saveas_btn_clicked();
    //一级菜单槽函数
    void file_switchPage();
    void seg_switchPage();
    void process_switchPage();
    void tool_switchPage();
    void set_switchPage();
    //二级菜单槽函数
    void pre_switchPage();
    void last_switchPage();
    void toolset_switchPage();
    void subset_switchPage();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
