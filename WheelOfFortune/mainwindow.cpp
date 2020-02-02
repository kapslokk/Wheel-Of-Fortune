#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//This function is to create a confirmation pop-up window and return true, if Yes has been pressed.
bool MainWindow::ConfirmationMsgBox(){
    QMessageBox ConfirmationMessage;
    ConfirmationMessage.setWindowTitle("Potwierdzenie");
    ConfirmationMessage.setText("Czy na pewno?");
    ConfirmationMessage.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    ConfirmationMessage.setDefaultButton(QMessageBox::No);
    if(ConfirmationMessage.exec()==QMessageBox::Yes){
        return true;
    }
    else{
        return false;
    }
}

//unction that returns a vector of all input names
QVector<QString> MainWindow::GetAllNames(){
    QVector<QString> TempVector;
    for(int i=0;i<ui->PlayerNamesTable->rowCount()-1;i++){
        TempVector.append(ui->PlayerNamesTable->item(i,0)->text());
    }
    return TempVector;
}

void MainWindow::on_AcceptButton_clicked()
{
    if(ConfirmationMsgBox()){
        QVector<QString> TempVector = GetAllNames();
        for(QString Name: TempVector){
            AllPlayers.append(new Player(Name));
        }
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_PlayerNamesTable_cellChanged(int row, int column)
{
    //Check if the last cell is filled, if it is, add a new column right below it.
    if(row == ui->PlayerNamesTable->rowCount()-1){
        ui->PlayerNamesTable->insertRow(row+1);
    }
}
