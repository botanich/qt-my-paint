#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "kek1";
    qpainter.begin(this);
    qDebug() << "kek2";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRectangle_triggered()
{
    qDebug() << "it even works";
    shape_num = rect_num;
}


void MainWindow::on_actionSquare_triggered()
{
    shape_num = square_num;
}


void MainWindow::on_actionEllipse_triggered()
{
    shape_num = ellipse_num;
}


void MainWindow::on_actionCircle_triggered()
{
    shape_num = circle_num;
}


void MainWindow::on_actionPie_triggered()
{
    shape_num = pie_num;
}


void MainWindow::on_actionRed_triggered()
{
    qcolor.~QColor();
    qcolor = QColor(Qt::red);
}


void MainWindow::on_actionYellow_triggered()
{
    qcolor.~QColor();
    qcolor = QColor(Qt::yellow);
}


void MainWindow::on_actionBlue_triggered()
{
    qcolor.~QColor();
    qcolor = QColor(Qt::blue);
}


void MainWindow::on_actionGreen_triggered()
{
    qcolor.~QColor();
    qcolor = QColor(Qt::green);
}


void MainWindow::on_actionWhite_triggered()
{
    qcolor.~QColor();
    qcolor = QColor(Qt::white);
}


void MainWindow::on_actionBlack_triggered()
{
    qcolor.~QColor();
    qcolor = QColor(Qt::black);
    ui->statusbar->showMessage("black");
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    draw_shape();
}

void MainWindow::draw_shape() {
    if (shape_num == rect_num) {
        qpainter.drawRect(qrect);
    } else if (shape_num == square_num) {
        int size = std::min(qrect.width(), qrect.height());
        qpainter.drawRect(qrect.left(), qrect.top(), size, size);
    } else if (shape_num == ellipse_num) {
        qpainter.drawEllipse(qrect.left(), qrect.top(), qrect.width(), qrect.height());
    } else if (shape_num == circle_num) {
        int size = std::min(qrect.width(), qrect.height());
        qpainter.drawEllipse(qrect.left(), qrect.top(), size, size);
    } else if (shape_num == 4) {
        qpainter.drawPie(qrect.left(), qrect.top(), qrect.width(), qrect.height(),
                         PIE_START_ANGLE, PIE_SPAN_ANGLE);
    }
    qpainter.end();
    edit_shape();
}

void MainWindow::edit_shape() {

}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "must be kek";
        qrect.setTopLeft(event->pos());
        during_drawing = true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (during_drawing && event->button() == Qt::LeftButton) {
        qDebug() << "must be drawing";
        qrect.setBottomRight(event->pos());
        during_drawing = false;
        draw_shape();
        during_editing = true;
    }
}
