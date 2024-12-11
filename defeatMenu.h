#ifndef DEFEATMENU_H
#define DEFEATMENU_H
#include <QPushButton>
#include "gameMenu.h"

//Nothing has been implemented here yet :)
class DefeatMenu:GameMenu{
public:
    virtual void showMenu() override;
private:
    QPushButton restartButton;
};

#endif // DEFEATMENU_H
