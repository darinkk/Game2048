#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <vector>
#include <list>

class Field{
public:
    //Field();
    Field(int fieldSize = 5);
    int getSize(){return size;}

    std::vector<std::vector<Cell>>& getField(){return field;}
    bool getMovableStatus(){return isMovable;}

    void updateMovability(); //Update field movability
    int moveCells(Direction dir); //Move all filled cells on field to direction dir
    void cleanField(); //Set all cells value as 0
    void createField(int fieldSize = 5); //Create field with new size
    void printFieldConsole(); //Print field to console (this function just for cheking)

    void FillFreeCells(int numCellsToFill = 1);//Add random numbers to random cells on field

private:
    int size;
    std::vector<std::vector<Cell>> field;
    bool isMovable;

    std::list<std::pair<int,int>> findFreeCells(); //Return coordinates of free cells
    int createRandomNummber(int min, int max); //Generate random value in [min,max]
    std::map<std::string, int> initStartPointsForMove(Direction direction); //Initialize start/end points and step for move depending on the direction
    void initializeField(); //Create cells and set neighbors for cells
    void setSize(int fieldSize); //For resizing field
};

#endif
