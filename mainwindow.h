#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QPaintEvent>

#define PIE_START_ANGLE 30*16
#define PIE_SPAN_ANGLE 120*16

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


enum shape_code {rect_num, square_num, ellipse_num, circle_num, pie_num};


class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(shape_code shape_num MEMBER shape_num);
    Q_PROPERTY(bool during_drawing MEMBER during_drawing);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:

    void on_actionRectangle_triggered();

    void on_actionEllipse_triggered();

    void on_actionSquare_triggered();

    void on_actionCircle_triggered();

    void on_actionPie_triggered();

    void on_actionRed_triggered();

    void on_actionYellow_triggered();

    void on_actionBlue_triggered();

    void on_actionGreen_triggered();

    void on_actionWhite_triggered();

    void on_actionBlack_triggered();

private:
    Ui::MainWindow *ui;

    QRect qrect;
    QPainter qpainter;
    QColor qcolor;
    shape_code shape_num;
    int test;
    bool during_drawing = false, during_editing = false;


    shape_code get_shape_num();

    void draw_shape();

    void edit_shape();
};
#endif // MAINWINDOW_H
