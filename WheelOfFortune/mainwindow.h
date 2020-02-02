#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <player.h>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<Player*> AllPlayers;

    bool ConfirmationMsgBox();
    QVector<QString> GetAllNames();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AcceptButton_clicked();

    void on_PlayerNamesTable_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
