#include "field.h"
#include <random>
#include <utility>
#include "numberGenerator.h"

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
}

void Field::updateMovability(){
    /*
    * Field is movable if at least one cell is movable
    */
    for(int i = 0; i<size; i++){
        for(int j = 0; j < size; j++){
            //Cell *cell = field[i][j];
            if(field[i][j].isMovable()){
                isMovable = true;
                return;
            }
        }
    }
    isMovable = false;
}

void Field::initializeField(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            field[i][j] = Cell();

            if(i-1>=0){ field[i][j].addNeighbor(Direction::UP, &field[i-1][j]); }
            else{ field[i][j].addNeighbor(Direction::UP, nullptr); }

            if(i+1 < size){ field[i][j].addNeighbor(Direction::DOWN, &field[i+1][j]); }
            else{ field[i][j].addNeighbor(Direction::DOWN, nullptr); }

            if(j-1 >= 0){ field[i][j].addNeighbor(Direction::LEFT, &field[i][j-1]); }
            else{ field[i][j].addNeighbor(Direction::LEFT, nullptr); }

            if(j+1 < size){ field[i][j].addNeighbor(Direction::RIGHT, &field[i][j+1]); }
            else{ field[i][j].addNeighbor(Direction::RIGHT, nullptr); }

        }
    }
    isMovable = true;
}

void Field::cleanField(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            field[i][j].setValue(0);
        }
    }
}

std::map<std::string, int> Field::initStartPointsForMove(Direction direction){
    std::map<std::string, int> startPoints;

    if(direction ==Direction::DOWN || direction == Direction::RIGHT){
        startPoints["start"] = size - 1;
        startPoints["end"] = 0;
        startPoints["step"] = -1;
        startPoints["error"] = 0;
    }
    else if(direction == Direction::UP || direction== Direction::LEFT){
        startPoints["start"] = 0;
        startPoints["end"] = size - 1;
        startPoints["step"] = 1;
        startPoints["error"] = 0;
    }
    else{startPoints["error"] = -1;}

    //std::cout << "start i/j: " << startPoints["start"] << "   end i/j: " << startPoints["end"] << std::endl;

    return startPoints;
}

int Field::moveAllCells(Direction direction){
    std::map<std::string, int> startPoints = initStartPointsForMove(direction);
    int incrementForScore = 0;
    if(startPoints["error"] != 0){
        return 0;
    }else{
        if(direction == Direction::UP || direction == Direction::DOWN){
            for(int i = startPoints["start"]; i != startPoints["end"] + startPoints["step"]; i += startPoints["step"]){
                for(int j = 0; j < size; j++){
                    if(field[i][j].getFilledStatus()){
                        int merged = field[i][j].moveCell(direction);
                        incrementForScore += merged;
                    }
                }
            }          
        }
        else if(direction == Direction::LEFT || direction == Direction::RIGHT){
            for(int i = 0; i < size; i++){
                for(int j = startPoints["start"]; j != startPoints["end"]  + startPoints["step"]; j += startPoints["step"]){
                    if(field[i][j].getFilledStatus()){
                        int merged = field[i][j].moveCell(direction);
                        incrementForScore += merged;
                    }
                }
            }
        }
        return incrementForScore;
    }
    return incrementForScore;
}

void Field::printFieldConsole(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << field[i][j].getValue() << " ";
        }
        std::cout << std::endl;
    }
}

std::list<std::pair<int,int>> Field::findFreeCells(){
    std::list<std::pair<int,int>> cordsOfFreeCells;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!field[i][j].getFilledStatus()){
                cordsOfFreeCells.push_back({i,j});
            }
        }
    }
    return cordsOfFreeCells;
}

void Field::FillFreeCells(int numCellsToFill){
    std::list<std::pair<int,int>> cordsOfFreeCells = findFreeCells();

    if(numCellsToFill > cordsOfFreeCells.size()){
        numCellsToFill = cordsOfFreeCells.size();
    }

    if (numCellsToFill == 0){
        return;
    }else if(numCellsToFill == 1 && cordsOfFreeCells.size() == 1){
        field[cordsOfFreeCells.begin()->first][cordsOfFreeCells.begin()->second].fillWithStandartValue();
        return;
    }else{
        for(int i = 0; i < numCellsToFill; i++){
            int freeCellIndex = NumberGenerator::createRandomNummber(0, cordsOfFreeCells.size()-1);

            auto iterator = cordsOfFreeCells.begin();
            std::advance(iterator,freeCellIndex);
            std::pair<int,int> cellCords = *iterator;

            field[cellCords.first][cellCords.second].fillWithStandartValue();

            cordsOfFreeCells.erase(iterator);
        }
    }
}
