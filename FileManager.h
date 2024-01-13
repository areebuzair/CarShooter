#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

//Score class to use as a datatype
class Score
{
public:
    std::string name;
    int score;

    Score();
    Score(std::string nm,int s);
};

//function used in sort function of addHigh
//DESCENDING ORDER
bool compareScore(const Score& a,const Score& b);


class HighScore
{
    std::vector<Score> entry;
public:

    void addHigh(std::string nm,int s);

    void displayHigh();

    int Least();

    std::string StringValue();
private:
    int loadHighScore();

    void saveHighScore() const;

};
