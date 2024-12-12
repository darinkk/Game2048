#ifndef VICTORYGAMEMENU_H
#define VICTORYGAMEMENU_H

#include <QPushButton>
#include "gameMenu.h"

class VictoryGameMenu : public  GameMenu{
    Q_OBJECT
public:
    VictoryGameMenu(QWidget *parent = nullptr);
    ~VictoryGameMenu() = default;
private:
    void setupUI() override;
private:
    QPushButton *startNewGameButton;
    QPushButton *continueGameButton;
signals:
    void startNewGameSignal();

};

#endif // VICTORYGAMEMENU_H
