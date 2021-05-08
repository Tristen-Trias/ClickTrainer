#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator64>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_goYellow_released();
    void on_goBlue_released();

    void on_G1_linkActivated(const QString &link);

    void on_G3_2_linkActivated(const QString &link);

    void on_asd_windowIconTextChanged(const QString &iconText);
    void updateLabel(const QString text);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
