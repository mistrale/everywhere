#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget menuList;
    QPushButton menu;
    QGridLayout *layout;
    QWidget widget;

public slots:
    void openMenu();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
