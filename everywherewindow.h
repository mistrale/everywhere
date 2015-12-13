#ifndef EVERYWHEREWINDOW_H
#define EVERYWHEREWINDOW_H

#include <QWidget>

#include <QMovie>

namespace Ui {
class EverywhereWindow;
}

namespace GUI {
    class EverywhereWindow : public QWidget
    {
         Q_OBJECT

    public:
        explicit EverywhereWindow(QWidget *parent = 0);
        ~EverywhereWindow();

    private:
        Ui::EverywhereWindow *ui;
        QMovie          *_background;
    };
}

#endif // EVERYWHEREWINDOW_H
