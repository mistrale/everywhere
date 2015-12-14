#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>

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
        Ui::Connection *ui;
    };
}

#endif // CONNECTION_H
