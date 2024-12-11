#ifndef CONVERTOR_H
#define CONVERTOR_H
#include "direction.h"
#include <vector>
#include <string>

class Convertor{
public:
    static Direction convertCorddsToDir(std::vector<std::vector<int>> mouseCoords);
    static Direction convertSignalToDir(std::string signal);
};

#endif // CONVERTOR_H
