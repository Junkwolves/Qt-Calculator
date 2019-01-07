#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void number_check();
    void on_dot_clicked();
    void calculations();
    void on_equally_clicked();
    void on_CE_clicked();
};

#endif // MAINWINDOW_H
