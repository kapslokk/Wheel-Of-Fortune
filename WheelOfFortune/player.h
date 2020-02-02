#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
    QString Name;
    int Score;
public:
    Player();
    Player(QString inputName){Name = inputName;}

    void incScore(int inputScore){Score += inputScore;}
    void setScore(int inputScore){Score = inputScore;}
    QString getName(){return Name;}
    int getScore(){return Score;}

};

#endif // PLAYER_H
