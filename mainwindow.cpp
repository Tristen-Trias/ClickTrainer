#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"
#include <QRandomGenerator>
#include <QCoreApplication>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRandomGenerator *r = QRandomGenerator::global();
    int rand = r->bounded(0, 16);
    const QString a = QString::number(rand);

    updateLabel(a);

    QPixmap pix("F:/Libraries/Documents/UCM/CSE/CSE 165/QT Projects/ClickTrainer/assets/circle.png");
    ui->G1->setPixmap(pix);
    ui->G2->setPixmap(pix);
    ui->G3->setPixmap(pix);
    ui->G4->setPixmap(pix);
    ui->G5->setPixmap(pix);
    ui->G6->setPixmap(pix);
    ui->G7->setPixmap(pix);
    ui->G8->setPixmap(pix);
    ui->G9->setPixmap(pix);
    ui->G10->setPixmap(pix);
    ui->G11->setPixmap(pix);
    ui->G12->setPixmap(pix);
    ui->G13->setPixmap(pix);
    ui->G14->setPixmap(pix);
    ui->G15->setPixmap(pix);
    ui->G16->setPixmap(pix);
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

void MainWindow::on_G3_2_linkActivated(const QString &link){
    ui->G3->setVisible(true);
}

void MainWindow::on_asd_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::updateLabel(const QString text)
{
    ui->asd->setText(text);
}
