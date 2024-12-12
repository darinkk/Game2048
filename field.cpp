#include "field.h"
#include <random>
#include <utility>
#include "numberGenerator.h"
#include <algorithm>

Field::Field(int fieldSize){
    setSize(fieldSize);
    isMovable = true;
}

void Field::setSize(int fieldSize){
    if(size != fieldSize){
        size = fieldSize;

        field.resize(size);
        for (int i = 0; i < size; i++){
            field[i].resize(size);
        }
    }
}

void Field::createField(int fieldSize){
    setSize(fieldSize);
    initializeField();
    cleanField();
}

void Field::updateMovability(){
    /*
    * Field is movable if at least one cell is movable
    */
    isMovable = false;
    //shouid not be loop here
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(field[i][j].isMovable()){
                isMovable = true;
                break;
            }
        }
        // isMovable = std::any_of(&field[0][0], &field[0][0] + size * size, [](Cell& cell) {
        //     return cell.isMovable(); });
    }

}

void Field::initializeField(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

            if(i-1>=0){ field[i][j].addNeighbor(Direction::UP, &field[i-1][j]); }

            if(i+1 < size){ field[i][j].addNeighbor(Direction::DOWN, &field[i+1][j]); }

            if(j-1 >= 0){ field[i][j].addNeighbor(Direction::LEFT, &field[i][j-1]); }

            if(j+1 < size){ field[i][j].addNeighbor(Direction::RIGHT, &field[i][j+1]); }
        }
    }
    isMovable = true;
}

void Field::cleanField(){
    for(int i = 0; i < size; i++){
        std::for_each(&field[i][0], &field[i][0] + size, [](Cell& cell) {
            cell.setValue(0); });
    }
}

const int Field::startIndex(Direction dir){
    if(dir == Direction::DOWN || dir == Direction::RIGHT){
        return size - 1;
    }else{
        return 0;
    }
}

const int Field::endIndex(Direction dir){
    if(dir == Direction::DOWN || dir == Direction::RIGHT){
        return 0;
    }else{
        return size - 1;
    }
}

const int Field::step(Direction dir){
    if(dir == Direction::DOWN || dir == Direction::RIGHT){
        return -1;
    }else{
        return 1;
    }
}

int Field::moveAllCells(Direction direction){
    int incrementForScore = 0;
        for(int i = startIndex(direction); i != endIndex(direction) + step(direction); i += step(direction)){
            for(int j = 0; j < size; j++){
                if(direction == Direction::UP || direction == Direction::DOWN){
                    if(field[i][j].getFilledStatus()){
                        int merged = field[i][j].moveCell(direction);
                        incrementForScore += merged;
                    }
                }else if(direction == Direction::LEFT || direction == Direction::RIGHT){
                    if(field[j][i].getFilledStatus()){
                        int merged = field[j][i].moveCell(direction);
                        incrementForScore += merged;
                    }
                }
            }
        }
    return incrementForScore;       
}

std::vector<Cell*> Field::findFreeCells(){
    std::vector<Cell*> iterators;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!field[i][j].getFilledStatus()){
                iterators.push_back(&field[i][j]);
            }
        }
    }
    return iterators;
}

void Field::FillFreeCells(int numCells){
    std::vector<Cell*> FreeCellsIterators = findFreeCells();

    if(numCells > FreeCellsIterators.size()){
        numCells = FreeCellsIterators.size();
    }

    if (numCells == 0){
        return;
    }else if(numCells == 1 && FreeCellsIterators.size() == 1){
        FreeCellsIterators[0]->fillWithStandartValue();
        return;
    }else{
        for(int i = 0; i < numCells; i++){
            int freeCellIndex = NumberGenerator::createRandomNummber(0, FreeCellsIterators.size()-1);

            FreeCellsIterators[freeCellIndex]->fillWithStandartValue();
            FreeCellsIterators.erase(FreeCellsIterators.begin() + freeCellIndex);
        }
    }
}
