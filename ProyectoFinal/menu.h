#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "player.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_new_game_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_author_clicked();

    void on_pushButton_information_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
