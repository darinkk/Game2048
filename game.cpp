#include "game.h"
#include <cmath>

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

void Game::moveByMouse(std::vector<std::vector<int>> mouseCoords){
    Direction direction;
    int incrementForScore = 0;
    //std::vector<std::vector<Cell>>& currentField = gameField.getField();
    //int vectorSize = mouseCoords.size();
    if (mouseCoords.size()< 2){
        std::cerr << "Not enough mouse points for move" << std::endl;
    }
    int xMove = mouseCoords[0][0] - mouseCoords[mouseCoords.size()-1][0];
    int yMove = mouseCoords[0][1] - mouseCoords[mouseCoords.size()-1][1];


    if(std::abs(xMove) > std::abs(yMove)) {
        //*HORIZONTAL*//
        if(xMove > 0){
            direction = Direction::RIGHT;
        }else{
            direction = Direction::LEFT;
        }
    }else{
        //*VERTICAL*//
        if(yMove > 0){
            direction = Direction::DOWN;
        }else{
            direction = Direction::UP;
        }
    }

    incrementForScore = gameField.moveCells(direction);
    gameScore.updateCurrentScore(incrementForScore);
}

Direction Game::convertSignalToDirection(std::string signal){
    Direction direction;
    //This logic can be changed, I don`t know now how will look "signal"
    if(signal == "a" || signal == "A"){
        direction = Direction::LEFT;
    }else if(signal == "w" || signal == "W"){
        direction = Direction::UP;
    }else if(signal == "d" || signal == "D"){
        direction = Direction::RIGHT;
    }else if(signal == "s" || signal == "S"){
        direction = Direction::DOWN;
    }
    return direction;
}

void Game::moveByKeyboard(std::string signal){
    Direction direction = convertSignalToDirection(signal);
    int incrementForScore = 0;

    // if(pressedKey == "a" || pressedKey == "A"){
    //     direction = "LEFT";
    // }else if(pressedKey == "w" || pressedKey == "W"){
    //     direction = "UP";
    // }else if(pressedKey == "d" || pressedKey == "D"){
    //     direction = "RIGHT";
    // }else if(pressedKey == "s" || pressedKey == "S"){
    //     direction = "DOWN";
    // }

    incrementForScore = gameField.moveCells(direction);
    gameScore.updateCurrentScore(incrementForScore);
}

void Game::startGame(int fieldSize){
    gameField.createField(fieldSize);
    int numberOfStartsValues = 6;
    gameField.addNumbers(numberOfStartsValues);

    // gameField.printFieldConsole();
    // gameScore.printScoreConsole();

    // moveByKeyboard("s");

    // gameField.printFieldConsole();
    // gameScore.printScoreConsole();
    // std::string dir = "d";

    // //std::cin >> dir;
    // moveByKeyboard(dir);
    // gameField.printFieldConsole();
    // gameScore.printScoreConsole();

}
