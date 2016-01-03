#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QWidget>

namespace Ui {
class Download;
}

namespace GUI {
    class Download : public QWidget
    {
        Q_OBJECT

    public:
        explicit Download(QWidget *parent = 0);
        ~Download();

    private:
        Ui::Download *ui;
    };
}

#endif // DOWNLOAD_H
