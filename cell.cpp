#include "cell.h"
#include <random>

Cell::Cell(int newValue){
    resetCell();
    value = newValue;
}

void Cell::resetCell(){
    value = 0;
    // xCoordinate = 0;
    // yCoordinate = 0;
    isFilled = false;

    neighbors[Direction::UP] = nullptr;
    neighbors[Direction::DOWN] = nullptr;
    neighbors[Direction::LEFT] = nullptr;
    neighbors[Direction::RIGHT] = nullptr;
}

bool Cell::cellIsMovable(){
    /*
    * Cell is movable if have al least one neighbor with the same
    * value or the its value = 0
    */
    for(const auto& pair: neighbors){
        Cell *neighbor = pair.second;
        if(neighbor != nullptr){
            if(!neighbor->isFilled || neighbor->value == value){
                return true;
            }
        }
    }
    return false;
}

int Cell::moveCellToDirection(Direction direction){
    /*
    * We move a cell if it`s movable.
    * We move a cell to direction while until it can move in the direction or
    * until it`s merged
    */
    Cell *neighbor = neighbors[direction];
    //std::cout << "moving..." << "   " << std::endl;
    int mergedSum = 0;
    if(neighbor != nullptr){
        if(!neighbor->isFilled){
            //std::cout << "moving to free cell..." << "   " << std::endl;
            //std::cout << "neighbor value/status: " << neighbor->getCellValue() << "/" << neighbor->getFilledStatus()<< std::endl;
            neighbor->setCellValue(value);
            //neighbor->isFilled = true;
            setCellValue(0);
            //std::cout << "moved!" << std::endl;
            mergedSum += neighbor->moveCellToDirection(direction);
            return mergedSum;
        }
        else if(neighbor->getCellValue() == value){
            // std::cout << "moving with merging..." << "   " << std::endl;
            // std::cout << "neighbor value/status: " << neighbor->getCellValue() << "/" << neighbor->getFilledStatus()<< std::endl;
            neighbor->setCellValue(getCellValue()*2);
            setCellValue(0);
            mergedSum += neighbor->getCellValue();
            //std::cout << "moved!" << std::endl;
            return mergedSum;
        }
    }else{
        //std::cout << "not moved!" << "   " << std::endl;
        return mergedSum;
    }
    return mergedSum;
}

void Cell::addNeighbor(Direction dir, Cell *neighbor){
    //if(dir == Direction::UP|| dir == Direction::DOWN || dir == Direction::LEFT || dir == Direction::RIGHT){
    neighbors[dir] = neighbor;
    //}
}

void Cell::updateFilledStatus(){
    isFilled = (value != 0);
}

Cell* Cell::getNeighbor(Direction dir){
    //if(dir == Direction::UP || dir == Direction::DOWN || dir == Direction::LEFT || dir == Direction::RIGHT){
    return neighbors[dir];
    //}
    //else{
    //    return nullptr;
    //}
}

void Cell::setCellValue(int newValue){
    value = newValue;
    updateFilledStatus();
}

void Cell::setCellValue(){
    /*
    * setCellValue() add random number from vector<int> values as cell value
    */
    std::vector<int> values = {2,4};

    std::random_device random;
    std::mt19937 generator((random()));
    std::uniform_int_distribution<> voter (0, values.size()-1);

    value = values[voter(generator)];
    // std::cout << "cell value: " << value << std::endl;
    // for(int i = 0; i <= 10; i++){
    //     int randomValue = values[voter(generator)];
    //     std::cout << randomValue << ' ';
    // }

    updateFilledStatus();
}


