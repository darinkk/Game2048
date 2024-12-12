#include "convertor.h"
#include <iostream>

Direction Convertor::convertCoordsToDir(std::vector<std::pair<int,int>> mouseCoords){
    Direction direction;

    if (mouseCoords.size() < 2){
        std::cerr << "Not enough mouse points for move" << std::endl;
    }
    int xMove = mouseCoords[0].first - mouseCoords[mouseCoords.size()-1].first;
    int yMove = mouseCoords[0].second - mouseCoords[mouseCoords.size()-1].second;

    if(std::abs(xMove) > std::abs(yMove)) {
        //*HORIZONTAL*//
        if(xMove > 0){
            direction = Direction::LEFT;
        }else{
            direction = Direction::RIGHT;
        }
    }else{
        //*VERTICAL*//
        if(yMove > 0){
            direction = Direction::UP;
        }else{
            direction = Direction::DOWN;
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
