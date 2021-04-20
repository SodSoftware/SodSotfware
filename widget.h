#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QFileDialog>
#include <QIODevice>
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <QHBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int status1;
    int status2;
    QGraphicsScene  *mainScene;
    QGraphicsPixmapItem *mainPixmapItem;
    cv::Mat mimage;
private slots:
    void on_file_btn_clicked();

    void on_pro_btn_clicked();

    void on_seg_btn_clicked();

    void on_set_btn_clicked();

    void on_tool_btn_clicked();

    void on_before_btn_clicked();

    void on_post_btn_clicked();

    void on_tconfirm_btn_clicked();

    void on_tcancel_btn_clicked();

    void on_sconfirm_btn_clicked();

    void on_scancel_btn_clicked();

    void on_about_btn_clicked();

    void on_open_btn_clicked();

    void on_save_btn_clicked();

    void on_saveas_btn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
