#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "game.h"
#include <QLabel>
#include <utility>
#include <QPushButton>
#include <QKeyEvent>
#include "convertor.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //const Game getGame(){return game;}

private slots:
    /*Slots for buttons event*/
    void onStartButtonClicked();
    void onRestartButtonClicked();

    //void receiveStartNewGameSignal();
    //void receiveContinueGameSignal();

private:
    /*Functions for setup UI*/
    void setupUI();
    void setupFieldLabels(/*QGridLayout *fieldGLayout*/); //used for setup field depending on game.field.size
    void setupScoresLabels(/*QVBoxLayout *scoreLayout*/); //used for setup best score and current score depending on game.score
    void setupStartButton(/*QVBoxLayout *buttonsLayout*/); //used for setup start button
    void setupRestartButton(); //used for setup restart button

    /*Functions for update UI*/
    void cleanLayout(QLayout *layout);
    void updateUI();
    void updateFieldLabels(); //used for updating field
    void updateScoresLabels(); //used for updating best score and current score
    //void updateButtonsLabels(); //used for detele start button and set restart button to UI

    /*Function for events*/
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;


    //void mouseMoveEvent(QMouseEvent *event) override;

    void showMenu(bool isWin);

private:
    Ui::MainWindow *ui;

    /*Game logic*/
    Game game;

    bool playAfterrWin;

    /*UI elements*/
    // std::vector<std::vector<QLabel*>> boxesForCells;
    QLabel *currentScoreLabel = new QLabel(this);
    QLabel *bestScoreLabel = new QLabel(this);
    QPushButton *startButton = new QPushButton(this);
    QPushButton *restartButton = new QPushButton(this);

    /*Layouts*/
    QGridLayout *fieldGLayout = new QGridLayout; //layout for field. Here added as many Text Browsers as there are cells on the field
    QVBoxLayout *scoreLayout = new QVBoxLayout; //Layout for score. Here will be added best score and current
    QVBoxLayout *buttonsLayout = new QVBoxLayout; //Layout for button(s). Here added all nedded buttons
    QVBoxLayout *scoreButtonLayout = new QVBoxLayout; //Layout for score and button. Here added scoreLayout and buttonLayout
    QHBoxLayout *mainHLayout = new QHBoxLayout; //It`s main layout. Here plased fieldGLayout | scoreButtonLayout


};
#endif // MAINWINDOW_H
