#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMovie>

#include <QtNetwork/QNetworkAccessManager>

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

    public slots:
        void                registerEverywhere();

    private:
        Ui::Registration        *ui;
        QMovie                  *_background;
        QNetworkAccessManager   _manager;
    };
}

#endif // REGISTRATION_H
