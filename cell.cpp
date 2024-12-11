#include "cell.h"
#include <random>
#include <algorithm>
#include  "numberGenerator.h"

Cell::Cell(int newValue){
    resetCell();
    value = newValue;
}

void Cell::resetCell(){
    value = 0;
    isFilled = false;

    neighbors[Direction::UP] = nullptr;
    neighbors[Direction::DOWN] = nullptr;
    neighbors[Direction::LEFT] = nullptr;
    neighbors[Direction::RIGHT] = nullptr;
}

bool Cell::isMovable(){
    /*
    * Cell is movable if have al least one neighbor with the same
    * value or the its value = 0
    */
    auto iterator = std::find_if(neighbors.begin(), neighbors.end(),[this](std::pair<Direction, Cell*> neighbor){
        return !neighbor.second->isFilled || neighbor.second->value == this->value;
    });

    return iterator != neighbors.end();

}

int Cell::moveCell(Direction direction){
    /*
    * We move a cell if it`s movable.
    * We move a cell to direction while until it can move in the direction or
    * until it`s merged
    */
    Cell *neighbor = neighbors[direction];
    int mergedSum = 0;
    if(neighbor != nullptr){
        if(!neighbor->isFilled){
            neighbor->setValue(value);
            setValue(0);
            mergedSum += neighbor->moveCell(direction);
        }
        else if(neighbor->getValue() == value){
            neighbor->setValue(getValue()*2);
            setValue(0);
            mergedSum += neighbor->getValue();
        }
        //I can move outside only return mergedSum  if i move setCellValue(0) andd/or
        //mergedSum += neighbor->getValue() it will change hoe cells move
        return mergedSum;
    }
    return mergedSum;
}

void Cell::addNeighbor(Direction dir, Cell *neighbor){
    if(directionValid(dir)){
        neighbors[dir] = neighbor;
    }
}

void Cell::updateFilledStatus(){
    isFilled = (value != 0);
}

bool Cell::directionValid(Direction dir){
    return dir == Direction::UP || dir == Direction::DOWN || dir == Direction::LEFT || dir == Direction::RIGHT;
}

Cell* Cell::getNeighbor(Direction dir){
    if(directionValid(dir)){
        return neighbors[dir];
    }
    else{
       return nullptr;
    }
}

void Cell::setValue(int newValue){
    value = newValue;
    updateFilledStatus();
}

void Cell::fillWithStandartValue(){
    std::vector<int> values = {2,4};
    value = values[NumberGenerator::createRandomNummber(0, values.size()-1)];
    updateFilledStatus();
}


