#include "victoryGameMenu.h"
#include "mainwindow.h"

VictoryGameMenu::VictoryGameMenu(QWidget *parent) : GameMenu(parent){
    setWindowTitle("Victory Menu");
    setupUI();
}


void VictoryGameMenu::setupUI(){
    setText("You are winner!");

    startNewGameButton = addButton("Start new game", QMessageBox::AcceptRole);
    continueGameButton = addButton("Continue current game", QMessageBox::RejectRole);

    connect(startNewGameButton, &QPushButton::clicked, this, &VictoryGameMenu::startNewGameSignal);

    setDefaultButton(startNewGameButton);
}

