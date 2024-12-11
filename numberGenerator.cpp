#include "numberGenerator.h"
#include <random>

int NumberGenerator::createRandomNummber(int min, int max){
    std::random_device random;
    std::mt19937 generator((random()));
    std::uniform_int_distribution<> voter (min, max);

    return voter(generator);
}
