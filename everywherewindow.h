#ifndef EVERYWHEREWINDOW_H
#define EVERYWHEREWINDOW_H

#include <vector>

#include <QWidget>
#include <QMovie>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QPushButton>

#include <QGraphicsItemAnimation>

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

        void                                closeMenu();
        void                                openMenu();

        void                                createCloseMenu();
        void                                createOpenMenu();

        void                                createQPropertyAnimationButton(const QRect &,
                                                                           const QRect &,
                                                                           QPushButton *,
                                                                           QParallelAnimationGroup *);

    public slots:
        void                                manageMenu();

    private:
        Ui::EverywhereWindow *ui;

        QParallelAnimationGroup             *_closeAnimations;
        QParallelAnimationGroup             *_openAnimations;

        QPropertyAnimation                  *_closeLastAnimation;
        QPropertyAnimation                  *_openLastAnimation;
        bool                                _menuOpen;


    };
}

#endif // EVERYWHEREWINDOW_H
