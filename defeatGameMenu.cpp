#include "defeatGameMenu.h"
#include "mainwindow.h"

DefeatGameMenu::DefeatGameMenu(QWidget *parent) : GameMenu(parent){
    setWindowTitle("Defeat Menu");
    setupUI();
}

void DefeatGameMenu::setupUI(){
    setText("You lost :(");

    startNewGameButton = addButton("Start new game", QMessageBox::AcceptRole);
    connect(startNewGameButton, &QPushButton::clicked, this, &DefeatGameMenu::startNewGameSignal);

    setDefaultButton(startNewGameButton);
}

void DefeatGameMenu::closeEvent(QCloseEvent *event) {
    startNewGameButton->click();
}
