#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "gameMenu.h"
#include "victoryGameMenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("2048");
    setupUI();
    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupFieldLabels(/*QGridLayout *fieldGLayout*/){
    int fieldSize = game.getSize();
    //boxesForCells.clear();

    for(int i = 0; i < fieldSize; i++){
        for(int j = 0; j < fieldSize; j++){
            //Cell cell = ;
            QLabel* cellLabel = new QLabel(this);
            cellLabel->setStyleSheet("background-color: lightblue; border: 1px solid darkblue; font-size: 16px; font-weight: bold");
            //cell->setMinimumSize(15,15);
            //cell->setMaximumSize(60,60);
            cellLabel->setText(QString::number(game.getFieldCells()[i][j].getValue()));
            cellLabel->setAlignment(Qt::AlignCenter);
            fieldGLayout->addWidget(cellLabel, i, j);
            //boxesForCells[i][j] = cellLabel;
        }
    }
}

void MainWindow::setupScoresLabels(/*QVBoxLayout *scoreLayout*/){

    //QLabel *currentScoreLabel = new QLabel(this);
    //currentScoreLabel->setStyleSheet();
    currentScoreLabel->setText("  Current score: " + QString::number(game.getScore().getCurrentScore()));
    currentScoreLabel->setStyleSheet("border-left: 2px solid darkblue;");
    currentScoreLabel->setFixedHeight(100);
    scoreLayout->addWidget(currentScoreLabel);


    //QLabel bestScoreLabel = new QLabel(this);
    //bestScore->setStyleSheet();
    bestScoreLabel->setText("  Best score: " + QString::number(game.getScore().getBestScore()));
    bestScoreLabel->setStyleSheet("border-left: 2px solid darkblue;");
    bestScoreLabel->setFixedHeight(100);
    scoreLayout->addWidget(bestScoreLabel);

    scoreLayout->addStretch();
}

void MainWindow::setupStartButton(/*QVBoxLayout *buttonsLayout*/){

    //QPushButton *startButton= new QPushButton(this);
    connect(startButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));

    startButton->setText("Start");

    startButton->setStyleSheet("background-color: lightblue; border: 1px solid darkblue; font-size: 20px");
    startButton->setFixedWidth(150);
    startButton->setFixedHeight(35);

    buttonsLayout->addWidget(startButton);
}

void MainWindow::setupRestartButton(){
    connect(restartButton, SIGNAL(clicked()), this, SLOT(onRestartButtonClicked()));

    restartButton->setText("Restart");

    restartButton->setStyleSheet("background-color: lightblue; border: 1px solid darkblue; font-size: 20px");
    restartButton->setFixedWidth(150);
    restartButton->setFixedHeight(35);

    buttonsLayout->addWidget(restartButton);
}

void MainWindow::setupUI(){

    this->setStyleSheet("background-color: lightgray;");
    this->setMaximumSize(800,700);
    this->setMinimumSize(400,300);

    //QGridLayout *fieldGLayout = new QGridLayout;
    setupFieldLabels(/*fieldGLayout*/);

    //QVBoxLayout *scoreLayout = new QVBoxLayout;
    setupScoresLabels(/*scoreLayout*/);

    //QVBoxLayout *buttonsLayout = new QVBoxLayout;
    setupStartButton(/*buttonsLayout*/);

    //QVBoxLayout *scoreButtonLayout = new QVBoxLayout;
    scoreButtonLayout->addLayout(scoreLayout);
    scoreButtonLayout->addLayout(buttonsLayout);


    //QHBoxLayout *mainHLayout = new QHBoxLayout;
    ui->centralwidget->setLayout(mainHLayout);
    mainHLayout->addLayout(fieldGLayout);
    mainHLayout->addSpacing(20);
    mainHLayout->addLayout(scoreButtonLayout);
    mainHLayout->setMargin(20); //temporary
}

void MainWindow::cleanLayout(QLayout *layout){
    //Logic for clean layout
    if(layout != nullptr){
        while(layout->count() > 0){
            QLayoutItem *item = layout->takeAt(0);
            if(item != nullptr){
                item->widget()->deleteLater();
                delete item;
            }
        }
    }
}

void MainWindow::updateUI(){
    updateFieldLabels();
    updateScoresLabels();
}

void MainWindow::updateFieldLabels(){
    int currentSize = fieldGLayout->count();
    int newSize = game.getSize();
    if(currentSize/newSize != newSize){
        cleanLayout(fieldGLayout);
        setupFieldLabels();
    }
    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            QLabel *cell = qobject_cast<QLabel*>(fieldGLayout->itemAtPosition(i,j)->widget());
            cell->setText(QString::number(game.getFieldCells()[i][j].getValue()));
        }
    }
}

void MainWindow::updateScoresLabels(){
    //Logic for update score label
    int currrScore = game.getScore().getCurrentScore();
    int bestScore = game.getScore().getBestScore();
    currentScoreLabel->setText("  Current score: " + QString::number(currrScore));
    if(currrScore > bestScore){
        bestScore = currrScore;
        bestScoreLabel->setText("  Best score: " + QString::number(bestScore));
    }
}

void MainWindow::onStartButtonClicked(){
    game.startGame();
    updateUI();
    cleanLayout(buttonsLayout);
    setupRestartButton();


    VictoryGameMenu meenu(this);
    //meenu.setModal(true);
    //meenu.exec();
}

void MainWindow::onRestartButtonClicked(){
    int fieldOfLabelsSize = sqrt(fieldGLayout->count());
    game.startGame(fieldOfLabelsSize);
    game.getScore().resetScore();
    updateUI();
}

void MainWindow::keyPressEvent(QKeyEvent *event){ //It can be better
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left){
        game.moveCellsOnField(Convertor::convertSignalToDir("LEFT"));
    }else if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right){
        game.moveCellsOnField(Convertor::convertSignalToDir("RIGHT"));
    }else if(event->key() == Qt::Key_W || event->key() == Qt::Key_Up){
        game.moveCellsOnField(Convertor::convertSignalToDir("UP"));
    }else if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down){
        game.moveCellsOnField(Convertor::convertSignalToDir("DOWN"));
    }

    updateUI();
}

// void MainWindow::mouseMoveEvent(QMouseEvent *event) {
//     std::vector<std::vector<int>> MouseCords;

//     int mouseX = event->pos().x();
//     int mouseY = event->pos().y();

//     MouseCords.push_back({mouseX, mouseY});

//     game.moveCellsOnField(Convertor::convertCorddsToDir(MouseCords));
// }
