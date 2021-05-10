#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QRandomGenerator64>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int score, ctime, count, t, low, avg, tot;
    int times[10];

    //Helper functions
    int randNumber4();
    int randNumber16();
    void setRandPos(QPushButton *btn);
    void updateAvg(int n);
    void updateLow(int n);
    void updateScore(int n, int a);
    void updateScore(int n);
    void updateScore();
    void updateTime(int n);


    //Widget functions
    QPushButton* buttonVisible(QPushButton* btn);
    QPushButton* randButton();
    QTimer *timer;
    QTime start, stop;


public slots:
    void updateTime();
    void timer60s();

private slots:

    //Grid gamemode functions
    void gridGame();
    void setGrid();
    void buttonClicked();

    //Reaction Gamemode functions
    void setReac();
    void on_start_released();
    void on_reacButton_released();

    //Widget Function
    void setButton(QPushButton *button);

    //Menu functions
    void on_goYellow_released();
    void on_goBlue_released();
    void on_grid_released();
    void on_reac_released();
    void on_goBlue_2_released();
    void on_goYellow_2_released();
};
#endif // MAINWINDOW_H
