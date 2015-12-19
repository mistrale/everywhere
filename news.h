#ifndef NEWS_H
#define NEWS_H

#include <QWidget>

namespace Ui {
class News;
}

namespace GUI {
    class News : public QWidget
    {
        Q_OBJECT

    public:
        explicit News(QWidget *parent = 0);
        ~News();

    private:
        Ui::News *ui;
    };
}

#endif // NEWS_H
