#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << "Running..." << std::endl;

    //Score score;
    //score.saveCurrentScoreToFile();

    // Cell cell;
    // cell.setCellValue();

    Game game;
    game.startGame();

    return a.exec();
}
