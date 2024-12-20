#include <iostream>
#include "score.h"


Score::Score(){
    //bestScore = 0;
    currentScore = 0;
    createScoreStorage();
    uploadBestScore();
}

Score::Score(std::string specialPath){
    //bestScore = 0;
    currentScore = 0;


    std::filesystem::path spcPath = specialPath;
    if(std::filesystem::exists(spcPath)){
        std::filesystem::create_directories(spcPath / "data");
        pathToStorage = spcPath / "data/scores.txt";
        std::cout << "Path to score file: " << pathToStorage << std::endl;
    }else{
        createScoreStorage();
    }

    uploadBestScore();
}

void Score::createScoreStorage(){
    try{
        std::filesystem::path pathToRun = std::filesystem::current_path();
        //std::cout << "Path to project: " << pathToProject << std::endl;

        while(pathToRun != pathToRun.root_path()){ //Looking for project directory (it will be mistake if CMakeLists.txt is deleted)
            std::cout << "Current path: " << pathToRun << std::endl;
            if(std::filesystem::exists(pathToRun / "CMakeLists.txt")){

                std::filesystem::path pathToProject = pathToRun;
                std::cout << "Path to project: " << pathToProject << std::endl;

                std::filesystem::path pathToFloder = pathToProject / "data";
                std::filesystem::create_directories(pathToFloder);

                pathToStorage = pathToFloder / "scores.txt";
                std::cout << "Path to score storage: " << pathToStorage << std::endl;
                break;
            }
            pathToRun = pathToRun.parent_path();
        }
    }
    catch(const std::filesystem::filesystem_error &err){
        std::cerr << "File processing error: " << err.what() << std::endl;
    }
}

void Score::saveCurrentScore(){
    if(currentScore != 0){
        scoreStorage.open(pathToStorage, std::ios::app);
        if(!scoreStorage.is_open()){
            std::cerr << "File not open and score not saved" << std::endl;
            return;
        }
        std::cout << "File is open..." << std::endl;


        scoreStorage << "," << currentScore;


        scoreStorage.close();
        std::cout << "File is closed" << std::endl;
    }
}

std::vector<int> Score::readScoresToInt(){
    scoreStorage.open(pathToStorage, std::ios::in);
    if(!scoreStorage.is_open()){
        std::cerr << "File not open and score not saved" << std::endl;
    }
    std::cout << "File is open..." << std::endl;

    std::string scoresSrt;
    std::getline(scoreStorage, scoresSrt);
    //std::cout << scoresSrt << std::endl;

    scoreStorage.close();
    std::cout << "File is closed" << std::endl;

    std::vector<int> scoresInt;
    int start = 0;
    int end = scoresSrt.find(',');
    while(end != std::string::npos){
        std::string value = scoresSrt.substr(start, end - start);
        scoresInt.push_back(std::stoi(value));

        start = end + 1;
        end = scoresSrt.find(',', start);
    }

    std::string value = scoresSrt.substr(start);
    scoresInt.push_back(std::stoi(value));

    std::cout << "Scores: " << std::endl;
    for(int i : scoresInt){
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return scoresInt;
}

void Score::uploadBestScore(){
    std::vector<int> scores;
    scores.clear();
    scores = readScoresToInt();
    for(int i : scores){
        if(i > bestScore){
            bestScore = i;
        }
    }
    std::cout << "Best score: " << bestScore << std::endl;
}

void Score::printScoreConsole(){
    std::cout << "Score: " << currentScore << std::endl;
    std::cout << "Best score: " << bestScore << std::endl;
}

void Score::resetScore(){
    currentScore = 0;
    uploadBestScore();
}
