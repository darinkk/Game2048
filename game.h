#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "score.h"

class Game{
public:
    //Game();
    Game(int fieldSize = 5);

    void startGame(int fieldSize = 5);
    void endGame(std::string condition);

private:
    Score gameScore;
    Field gameField;
    bool winStatus;
    bool loseStatus;

    void updateScore(int increment){gameScore.updateCurrentScore(increment);}
    void updateWinStatus(); //Check if player win
    void updateLoseStatus(); //Check if player lose
    void moveByMouse(std::vector<std::vector<int>> mouseCoords);
    void moveByKeyboard(std::string pressedKey);
};

#endif // GAME_H
