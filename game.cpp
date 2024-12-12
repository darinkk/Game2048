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

    // winStatus = false;
    // loseStatus = false;
    updateWinStatus();
    updateLoseStatus();

}

void Game::endGame(){
    if(gameScore.getCurrentScore() > 0){
        gameScore.saveCurrentScore();
    }
    gameField.cleanField();
    updateWinStatus();
    updateLoseStatus();
}

void Game::updateWinStatus(){
    winStatus = false;
    //should not be loop here
    for(int i = 0; i < gameField.getSize(); i++){
        for(int j = 0; j < gameField.getSize(); j++){
            if(gameField.getField()[i][j].haveWinValue()){
                winStatus = true;
                break;
            }
        }
        // winStatus = std::any_of(&gameField.getField()[i][0], &gameField.getField()[i][0] + gameField.getSize(),
        //     [](Cell& cell) { return cell.haveWinValue(); });
    }
}

void Game::updateLoseStatus(){
    loseStatus = !gameField.getMovableStatus();
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


