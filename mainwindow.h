#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
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
    QTimer *timer;

    int randNumber16();
    int randNumber4();
    int score;
    void updateScore(int n);
    void updateScore();
    QPushButton* buttonVisible(QPushButton* btn);
    QPushButton* randButton();

public slots:
    void startTimer();

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
};
#endif // MAINWINDOW_H
