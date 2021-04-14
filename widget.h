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
    void file_switchPage();
    void seg_switchPage();
    void process_switchPage();
    void tool_switchPage();
    void set_switchPage();
    int status;
private slots:
    void on_file_btn_clicked();

    void on_open_btn_clicked();

    void on_save_btn_clicked();

    void on_saveas_btn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
