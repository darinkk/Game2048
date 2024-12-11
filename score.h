#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

class Score{
public:
    Score();
    Score(std::string specialPath);
    int getBestScore(){return bestScore;}
    int getCurrentScore(){return currentScore;}
    //void setScoreFile(std::string specialPath){specialPath = way;}
    void saveCurrentScore();
    void updateCurrentScore(int increment){currentScore += increment;}
    void printScoreConsole(); //(this function just for cheking) //**//
    void resetScore();

private:
    void createScoreStorage(); //Create directory "data" and file score.txt in game2028/data
    std::vector<int> readScoresToInt(); //Read score history to vector<int>
    void uploadBestScore(); //Find and set best score

private:
    int bestScore;
    int currentScore;
    std::filesystem::path pathToStorage;
    std::fstream scoreStorage;
};

#endif // SCORE_H
