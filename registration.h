#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class Registration;
}

namespace GUI {
    class Registration : public QWidget
    {
        Q_OBJECT

    public:
         explicit Registration(QWidget *parent = 0);
         ~Registration();

    private:
        Ui::Registration *ui;
    };
}

#endif // REGISTRATION_H
