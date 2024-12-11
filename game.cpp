#include "game.h"
#include <algorithm>

Game::Game(int fieldSize){
    gameField.createField(fieldSize);
    winStatus = false;
    loseStatus = false;
}

const void Game::startGame(int fieldSize){
    gameField.createField(fieldSize);
    int numberOfStartsValues = 2;
    gameField.FillFreeCells(numberOfStartsValues);

    gameField.printFieldConsole();
    gameScore.printScoreConsole();
}

void Game::updateWinStatus(){
    for(int i = 0; i < gameField.getSize(); i++){
        winStatus = std::any_of(&gameField.getField()[i][0], &gameField.getField()[i][0] + gameField.getSize(), [](Cell& cell) {
            return cell.haveWinValue(); });
    }
}

void Game::updateLoseStatus(){
    loseStatus = (!gameField.getMovableStatus());
}

void Game::moveCellsOnField(Direction direction){

    int incrementForScore = 0;

    std::vector<std::vector<Cell>> fieldBefore = gameField.getField();

    incrementForScore = gameField.moveAllCells(direction);
    gameScore.updateCurrentScore(incrementForScore);

    bool fieldWasChanged = false;
    for(int i = 0; i < gameField.getSize(); i ++){
        for (int  j = 0; j < gameField.getSize(); j++){
            if(gameField.getField()[i][j].getValue() != fieldBefore[i][j].getValue()){
                fieldWasChanged = true;
                break;
            }
        }
    }

    if(fieldWasChanged){
        gameField.FillFreeCells(1);
    }

    updateWinStatus();
    updateLoseStatus();
}


