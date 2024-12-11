#include "convertor.h"
#include <iostream>

Direction Convertor::convertCorddsToDir(std::vector<std::vector<int>> mouseCoords){
    Direction direction;

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
    return direction;
}

Direction Convertor::convertSignalToDir(std::string signal){
    Direction direction;

    if(signal == "LEFT"){
        direction = Direction::LEFT;
    }else if(signal == "UP"){
        direction = Direction::UP;
    }else if(signal == "RIGHT"){
        direction = Direction::RIGHT;
    }else if(signal == "DOWN"){
        direction = Direction::DOWN;
    }
    return direction;
}
