#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QCoreApplication>
#include <QIcon>

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

    //ui->reacButton->setGeometry();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTimer()
{

}

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



QPushButton* MainWindow::buttonVisible(QPushButton* btn) {
    if (!btn->isVisible())
        return btn;
    else {
        btn = randButton();
        return buttonVisible(btn);
    }
}

void MainWindow::setGrid() {
    QLayoutItem* item;
    for (int i = 0; i < ui->gridLayout->rowCount(); i++) {
        for (int j = 0; j < ui->gridLayout->columnCount(); j++) {
            item = ui->gridLayout->itemAtPosition(i, j);
            if (item->widget()) {
                QPushButton* btn = qobject_cast<QPushButton *>(item->widget());
                connect(btn, &QPushButton::clicked, this, &MainWindow::buttonClicked);
                setButton(btn);
                btn->setVisible(false);
            }
        }
    }
    updateScore(0);
}

QPushButton* MainWindow::randButton() {
    int x, y;
    x = randNumber4();
    y = randNumber4();

    QLayoutItem *temp = ui->gridLayout->itemAtPosition(x, y);
    QPushButton *btn = qobject_cast<QPushButton *>(temp->widget());

    return btn;
}

void MainWindow::gridGame() {
    QPushButton* btn;

    setGrid();

    for (int i = 0; i < 3; i++) {
        btn = randButton();
        btn->setVisible(true);
    }

}

int MainWindow::randNumber16() {
    return rand() % 15;
}

int MainWindow::randNumber4() {
    return rand() % 3;
}

void MainWindow::setReac() {
    setButton(ui->reacButton);
}

void MainWindow::setButton(QPushButton* button) {
    const QPixmap pix("F:/Libraries/Documents/UCM/CSE/CSE 165/QT Projects/ClickTrainer/assets/circle.png");
    QIcon icon(pix);

    button->setFixedSize(icon.actualSize(icon.availableSizes().first()));
    button->setText("");
    button->setIcon(icon);
    button->setIconSize(icon.availableSizes().first());
}

void MainWindow::on_goYellow_released() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_goBlue_released()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_grid_released()
{
    ui->stackedWidget->setCurrentIndex(2);
    gridGame();
}

void MainWindow::on_reac_released()
{
    ui->stackedWidget->setCurrentIndex(1);
    setReac();
}

void MainWindow::updateLabel(const QString text, QLabel* label)
{
    label->setText(text);
}
