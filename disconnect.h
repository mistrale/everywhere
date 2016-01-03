#ifndef DISCONNECT_H
#define DISCONNECT_H

#include <QWidget>

namespace Ui {
class Disconnect;
}

namespace GUI {
    class Disconnect : public QWidget
    {
        Q_OBJECT

    public:
        explicit Disconnect(QWidget *parent = 0);
        ~Disconnect();

    private:
        Ui::Disconnect *ui;
    };
}

#endif // DISCONNECT_H
