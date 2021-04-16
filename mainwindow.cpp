#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goYellow_released() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_goBlue_released()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_G1_linkActivated(const QString &link)
{

}
