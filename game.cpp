#include "game.h"


Game::Game(int fieldSize){
    gameField.createField(fieldSize);
    winStatus = false;
    loseStatus = false;
}

void Game::updateWinStatus(){
    std::vector<std::vector<Cell>>& currentField = gameField.getField();
    for(int i = 0; i < gameField.getSize(); i++){
        for(int j = 0; j < gameField.getSize(); j++){
            if(currentField[i][j].haveWinValue()){
                winStatus = true;
                return;
            }
        }
    }
    winStatus = false;
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
        gameField.FillFreeCells();
    }

    updateWinStatus();
    updateLoseStatus();
}

void Game::startGame(int fieldSize){
    gameField.createField(fieldSize);
    int numberOfStartsValues = 2;
    gameField.FillFreeCells(numberOfStartsValues);

    gameField.printFieldConsole();
    gameScore.printScoreConsole();

}
