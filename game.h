#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "score.h"
#include <cmath>

class Game{
public:
    Game(int fieldSize = 5);
    const void startGame(int fieldSize = 5);
    void endGame(std::string condition);
    int getSize(){return gameField.getSize();}
    std::vector<std::vector<Cell>> getFieldCells(){return gameField.getField();}
    Score& getScore(){return gameScore;}
    void moveCellsOnField(Direction direction);

private:
    void updateScore(int increment){gameScore.updateCurrentScore(increment);}
    void updateWinStatus(); //Check if player win
    void updateLoseStatus(); //Check if player lose

private:
    Score gameScore;
    Field gameField;
    bool winStatus;
    bool loseStatus;
};

#endif // GAME_H
