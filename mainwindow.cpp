#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QCoreApplication>
#include <QIcon>
#include <QSizePolicy>
#include <QDebug>
#include <QTime>

#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Grid gamemode

void MainWindow::buttonClicked() {
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    QPushButton *temp;

    if (btn->isVisible()) {
        updateScore();
        temp = buttonVisible(randButton());
        btn->setVisible(false);
        temp->setVisible(true);
    }
}

void MainWindow::gridGame() {
    QPushButton* btn;

    setGrid();
    timer60s();

    for (int i = 0; i < 3; i++) {
        btn = randButton();
        btn->setVisible(true);
    }

}

void MainWindow::setGrid() {
    QLayoutItem* item;

    for (int i = 0; i < ui->gridLayout->rowCount(); i++) {
        for (int j = 0; j < ui->gridLayout->columnCount(); j++) {

            item = ui->gridLayout->itemAtPosition(i, j);

            if (item->widget()) {
                QPushButton* btn = qobject_cast<QPushButton *>(item->widget());

                connect(btn, &QPushButton::pressed, this, &MainWindow::buttonClicked);
                setButton(btn);
                btn->setVisible(false);
            }

        }
    }
    updateScore(0);
}

//End grid gamemode


//Reaction gamemode

void MainWindow::on_start_released()
{
    start = QTime::currentTime();
    ui->start->setVisible(false);
    setRandPos(ui->reacButton);
    ui->reacButton->setVisible(true);
}

void MainWindow::setRandPos(QPushButton* btn) {
    int x, y;

    //(max - min + 1) - min
    x = rand() % (1300 - 200 + 1) + 200;
    y = rand() % (600 - 100 + 1) + 100;

    btn->move(x, y);
}

void MainWindow::setReac() {
    setReacButton(ui->reacButton);
    ui->reacButton->setVisible(false);
    ui->start->setVisible(true);

    count = 0;
    low = INT_MAX;
    avg = 0;
    tot = 0;

}

void MainWindow::on_reacButton_released()
{
    stop = QTime::currentTime();
    ui->start->setVisible(true);
    ui->reacButton->setVisible(false);

    t = start.msecsTo(stop);
    updateTime(t);

    times[count] = t;
    tot += t;
    count++;
    avg = tot / count;


    updateAvg(avg);

    if (t < low) {
        low = t;
        updateLow(t);
    }

    if (count == 10) {
        ui->stackedWidget->setCurrentIndex(4);

        QString temp = QString::number(low);
        ui->scoreLow->setText("Lowest time: " + temp + " ms");

        temp = QString::number(avg);
        ui->scoreAvg->setText("Average: " + temp + " ms");

    }

}

//End Reaction Gamemode



//Widget Functions


void MainWindow::setReacButton(QPushButton* button) {
    const QPixmap pix("F:/Libraries/Documents/UCM/CSE/CSE 165/QT Projects/ClickTrainergit/assets/smallCircle.png");
    QIcon icon(pix);

    button->setFixedSize(icon.actualSize(icon.availableSizes().first()));
    button->setText("");
    button->setIcon(icon);
    button->setIconSize(icon.actualSize(icon.availableSizes().first()));
}

void MainWindow::setButton(QPushButton* button) {
    const QPixmap pix("F:/Libraries/Documents/UCM/CSE/CSE 165/QT Projects/ClickTrainergit/assets/circle.png");
    QIcon icon(pix);

    button->setFixedSize(icon.actualSize(icon.availableSizes().first()));
    button->setText("");
    button->setIcon(icon);
    button->setIconSize(icon.actualSize(icon.availableSizes().first()));
}

QPushButton* MainWindow::randButton() {
    int x, y;
    x = randNumber4();
    y = randNumber4();

    QLayoutItem *temp = ui->gridLayout->itemAtPosition(x, y);
    QPushButton *btn = qobject_cast<QPushButton *>(temp->widget());

    if (btn->isVisible())
        return randButton();

    return btn;
}

QPushButton* MainWindow::buttonVisible(QPushButton* btn) {
    if (!btn->isVisible())
        return btn;
    else {
        btn = randButton();
        return buttonVisible(btn);
    }
}

//End widget functions





//Label functions

void MainWindow::updateScore(int n, int a) {
    score = n + a;
    QString temp = QString::number(score);
    ui->score->setText("Score: " + temp);
}

void MainWindow::updateScore(int n) {
    score = n;
    QString temp = QString::number(score);
    ui->score->setText("Score: " + temp);
}

void MainWindow::updateScore() {
    score += 1;
    QString temp = QString::number(score);
    ui->score->setText("Score: " + temp);
}

void MainWindow::updateTime(int n) {
    QString temp = QString::number(n);
    ui->lTime->setText("Last time: " + temp + " ms");
}

void MainWindow::updateLow(int n) {
    QString temp = QString::number(n);
    ui->low->setText("Lowest time: " + temp + " ms");
}

void MainWindow::updateAvg(int n) {
    QString temp = QString::number(n);
    ui->avg->setText("Average: " + temp + " ms");
}

//End label functions





//Helper/Menu functions

void MainWindow::timer60s() {
    ctime = 60;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);
}

void MainWindow::updateTime() {
    ctime--;
    QString temp = QString::number(ctime);
    ui->time->setText("Time: " + temp);
    if (ctime == 0) {
        temp = QString::number(score);
        ui->stackedWidget->setCurrentIndex(3);
        ui->score_3->setText("Score: " + temp);
    }
}

int MainWindow::randNumber16() {
    return rand() % 15;
}

int MainWindow::randNumber4() {
    return rand() % 3;
}

void MainWindow::on_goYellow_released() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_goBlue_released() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_goBlue_2_released() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_goYellow_2_released() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_grid_released() {
    ui->stackedWidget->setCurrentIndex(2);
    gridGame();
}

void MainWindow::on_reac_released() {
    ui->stackedWidget->setCurrentIndex(1);
    setReac();
}

//End Helper/Menu functions
