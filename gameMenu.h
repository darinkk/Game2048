#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QMessageBox>
#include <QPushButton>
// #include "victoryGameMenu.h"
// #include "defeatGameMenu.h"

class GameMenu : public QMessageBox{
    Q_OBJECT
public:
    GameMenu(QWidget *parent = nullptr);
    ~GameMenu() = default;

private:
    virtual void setupUI() = 0;

};

#endif // GAMEMENU_H
