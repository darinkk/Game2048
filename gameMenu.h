#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "message.h"
#include <string>
#include <QMenu>

//This class can be changed :)
class GameMenu{
public:
    Menu();
    Menu(std::string mes){message.changeMessage(mes);}
    virtual void showMenu() = 0;
private:
    Message message;
};

#endif // GAMEMENU_H
