#ifndef RESEARCH_H
#define RESEARCH_H

#include <QWidget>

namespace Ui {
class Research;
}

namespace GUI {
    class Research : public QWidget
    {
        Q_OBJECT

    public:
        explicit Research(QWidget *parent = 0);
        ~Research();

    private:
        Ui::Research *ui;
    };
}

#endif // RESEARCH_H
