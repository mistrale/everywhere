#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <QWidget>

namespace Ui {
class Synchronization;
}

namespace GUI {
    class Synchronization : public QWidget
    {
        Q_OBJECT

    public:
        explicit Synchronization(QWidget *parent = 0);
        ~Synchronization();

    private:
        Ui::Synchronization *ui;
    };
}

#endif // SYNCHRONIZATION_H
