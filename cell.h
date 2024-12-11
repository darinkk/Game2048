#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <map>
#include <string>
#include "direction.h"

class Cell{
public:
    Cell(){resetCell();}
    Cell(int v);
    bool isMovable(); //Check if the cell is movable
    bool haveWinValue(){return value >= 2048;} //Check if the cell contains win value (2048)
    const int getValue(){return value;}
    int moveCell(Direction direction); //Move cell value to next cell in direction dir if possible
    void addNeighbor(Direction dir, Cell *neighbor); //Add/chenge cell neighbor (only UP,DOWN,LEFT,RIGHT)
    void setValue(int newValue); //Set cell value as newValue
    void fillWithStandartValue(); //Set cell value as a random value (2 or 4)
    bool getFilledStatus(){return isFilled;}
    Cell* getNeighbor(Direction dir); //Return pointer to neighbor by direction dir

private:
    void resetCell(); //set all members as default
    void updateFilledStatus();
    bool directionValid(Direction dir);

private:
    int value;
    std::map<Direction, Cell*> neighbors;
    bool isFilled;
};

#endif
