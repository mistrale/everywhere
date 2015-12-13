#ifndef REGIRSTRATION_H
#define REGIRSTRATION_H

#include <QWidget>

namespace Ui {
class regirstration;
}

class regirstration : public QWidget
{
    Q_OBJECT

public:
    explicit regirstration(QWidget *parent = 0);
    ~regirstration();

private:
    Ui::regirstration *ui;
};

#endif // REGIRSTRATION_H
