#ifndef STREAM_H
#define STREAM_H

#include <QWidget>

namespace Ui {
class Stream;
}

namespace GUI {
    class Stream : public QWidget
    {
        Q_OBJECT

    public:
        explicit Stream(QWidget *parent = 0);
        ~Stream();

    private:
        Ui::Stream *ui;
    };
}

#endif // STREAM_H
