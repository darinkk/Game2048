#ifndef DEFEATGAMEMENU_H
#define DEFEATGAMEMENU_H

#include "gameMenu.h"

class DefeatGameMenu : public  GameMenu{
    Q_OBJECT
public:
    DefeatGameMenu(QWidget *parent = nullptr);
    ~DefeatGameMenu() = default;
signals:
    void startNewGameSignal();
private:
    void setupUI() override;
    void closeEvent(QCloseEvent *event) override;
private:
    QPushButton *startNewGameButton;
};

#endif // DEFEATGAMEMENU_H
