#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "player.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_pushButton_enter_clicked();

    void on_pushButton_enter_2_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H

