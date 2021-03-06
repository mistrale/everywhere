#ifndef RESULTSEARCH_H
#define RESULTSEARCH_H

#include <QWidget>

namespace Ui {
class ResultSearch;
}

namespace GUI {
    class ResultSearch : public QWidget
    {
        Q_OBJECT

    public:
        explicit ResultSearch(QWidget *parent = 0);
        ~ResultSearch();

    private:
        Ui::ResultSearch *ui;

        QWidget     *_parent;
    };
}

#endif // RESULTSEARCH_H
