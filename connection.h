#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>
#include  <QNetworkAccessManager>

namespace Ui {
class Connection;
}

namespace GUI {
    class Connection : public QWidget
    {
        Q_OBJECT

    public:
        explicit Connection(QWidget *parent = 0);
        ~Connection();

    private:
        Ui::Connection  *ui;
        QMovie          *_background;

    public slots:
        void        connectEverywhere();
        void        replyFinished(QNetworkReply *);
    };
}

#endif // CONNECTION_H
