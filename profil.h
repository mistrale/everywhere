#ifndef PROFIL_H
#define PROFIL_H

#include <QWidget>

namespace Ui {
class Profil;
}

namespace GUI {
    class Profil : public QWidget
    {
        Q_OBJECT

    public:
        explicit Profil(QWidget *parent = 0);
        ~Profil();

    private:
        Ui::Profil *ui;
    };
}

#endif // PROFIL_H
