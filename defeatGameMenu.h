#ifndef DEFEATGAMEMENU_H
#define DEFEATGAMEMENU_H

#include "gameMenu.h"

class DefeatGameMenu : public  GameMenu{
    Q_OBJECT
public:
    DefeatGameMenu(QWidget *parent = nullptr);
    ~DefeatGameMenu() = default;
private:
    void setupUI() override;
    void closeEvent(QCloseEvent *event) override;
private:
    QPushButton *startNewGameButton;
signals:
    void startNewGameSignal();
};

#endif // DEFEATGAMEMENU_H
