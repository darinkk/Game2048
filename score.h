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
    //void setScoreFile(std::string specialPath){specialPath = way;}
    void saveCurrentScoreToFile();
    void updateCurrentScore(int increment){currentScore += increment;}

    void printScoreConsole(); //(this function just for cheking) //**//

private:
    int bestScore;
    int currentScore;
    std::filesystem::path pathToFile;
    std::fstream scoreFile;

    void setScoreFile(); //Create directory "data" and file score.txt in game2028/data
    std::vector<int> readScoresToInt(); //Read score history to vector<int>
    void uploadBestScore(); //Find and set best score
};

#endif // SCORE_H
