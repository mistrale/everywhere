#ifndef RADIO_H
#define RADIO_H

#include <QWidget>

namespace Ui {
class Radio;
}

namespace GUI {
    class Radio : public QWidget
    {
        Q_OBJECT

    public:
        explicit Radio(QWidget *parent = 0);
        ~Radio();

    private:
        Ui::Radio *ui;
    };
}

#endif // RADIO_H
