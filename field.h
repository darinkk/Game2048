#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <vector>
#include <list>

class Field{
public:
    Field(int fieldSize = 5);
    int getSize(){return size;}
    std::vector<std::vector<Cell>> getField(){return field;}
    bool getMovableStatus(){return isMovable;}
    int moveAllCells(Direction dir);
    void cleanField();
    void createField(int fieldSize = 5);
    void FillFreeCells(int numCells);//Add random numbers to random cells on field
    void updateMovability();

private:
    std::vector<Cell*> findFreeCells();
    void initializeField(); //set neighbors for cells
    void setSize(int fieldSize);
    int startIndex(Direction dir) const;
    int endIndex(Direction dir) const;
    int step(Direction dir) const;

private:
    int size;
    std::vector<std::vector<Cell>> field;
    bool isMovable;
};



#endif
