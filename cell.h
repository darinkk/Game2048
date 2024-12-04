#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <map>
#include <string>

class Cell{
public:
    Cell(){resetCell();}
    Cell(int v);
    bool cellIsMovable(); //Check if the cell is movable
    bool haveWinValue(){return value >= 2048;} //Check if the cell contains win value (2048)
    int getCellValue(){return value;}
    int moveCellToDirection(std::string dir); //Move cell value to next cell in direction dir if possible
    void addNeighbor(std::string dir, Cell *neighbor); //Add/chenge cell neighbor (only "UP","DOWN","LEFT","RIGHT")
    void setCellValue(int newValue); //Set cell value as newValue
    void setCellValue(); //Set cell value as a random value (2 or 4)

    bool getFilledStatus(){return isFilled;}
    Cell* getNeighbor(std::string dir); //Return pointer to neighbor by direction dir



private:
    int value;
    std::map<std::string, Cell*> neighbors;
    //int xCoordinate;
    //int yCoordinate;
    bool isFilled;

    void resetCell(); //set all members as default
    void updateFilledStatus(); //Update cell filled status

};

#endif
