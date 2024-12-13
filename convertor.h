#ifndef CONVERTOR_H
#define CONVERTOR_H
#include "direction.h"
#include <vector>
#include <string>

class Convertor{
public:
    static Direction convertCoordsToDir(std::vector<std::pair<int,int>> mouseCoords);
};

#endif // CONVERTOR_H
