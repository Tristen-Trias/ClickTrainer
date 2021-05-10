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

    int randNumber16();
    int randNumber4();

    void setRandPos(QPushButton *btn);
    void updateScore(int n, int a);
    void updateScore(int n);
    void updateScore();
    void updateLow(int n);
    void updateTime(int n);
    void updateAvg(int n);

    QPushButton* buttonVisible(QPushButton* btn);
    QPushButton* randButton();
    QTimer *timer;
    QTime start, stop;


public slots:
    void updateTime();
    void timer60s();

private slots:
    void on_goYellow_released();
    void on_goBlue_released();
    void on_grid_released();
    void on_reac_released();

    void updateLabel(const QString text, QLabel* label);

    void gridGame();
    void setGrid();
    void setReac();
    void setButton(QPushButton *button);
    void buttonClicked();
    void on_goBlue_2_released();
    void on_reacButton_released();
    void on_start_released();
    void on_goYellow_2_released();
};
#endif // MAINWINDOW_H
