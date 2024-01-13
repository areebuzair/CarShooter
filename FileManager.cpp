#include "FileManager.h"

//Score class to use as a datatype
Score::Score() : name(" "), score(0) {}
Score::Score(std::string nm,int s) : name(nm), score(s) {}

//function used in sort function of addHigh
//DESCENDING ORDER
bool compareScore(const Score& a,const Score& b)
{
    return (a.score > b.score);
}


void HighScore::addHigh(std::string nm,int s)
{
    //loads registered score in file if there is any
    loadHighScore();

    //loads entry in vector
    Score sco(nm,s);
    entry.push_back(sco);

    //sorts vector
    sort(entry.begin(),entry.end(),compareScore);

    //for top 3 high scores can be modified for required top scores
    if(entry.size() > 3)
    {
        entry.resize(3);
    }

    //writes all highscores in file
    saveHighScore();
}

void HighScore::displayHigh()
{
    std::cout << "High Scores: " << std::endl;

    int type = loadHighScore();

    if(type)
    {
        // 'n' to record serial int for high score
        int n = 0;
        for(const auto& hiScore : entry)
        {
            n++;
            std::cout << n << ". "<< hiScore.name << " ------------- " << hiScore.score << std::endl;

        }
        while(n != 3)
        {
            n++;
            std::cout << n << ". XXX ------------- 0  " << std::endl;
        }
    }

    else
    {
        for(int i=0; i<3; i++)
        {
            std::cout << (i+1) << ". XXX ------------- 0  " << std::endl;
        }
    }
}


int HighScore::loadHighScore()
{
    entry.clear();

    std::ifstream inFile("HighScores.DAT", std::ios::binary);
    if(!inFile)
    {
        std::cout << "Can't open File." << std::endl;
        return 0;
    }

    std::string name;
    int score;
    Score loaded;

    //takes input from file
    while(inFile >> name >> score)
    {
        //inFile.read(reinterpret_cast<char*>(&loaded), sizeof(loaded));
        Score loaded(name,score);
        entry.push_back(loaded);
    }

    inFile.close();
    return 1;
}

void HighScore::saveHighScore() const
{
    std::ofstream outFile("HighScores.DAT", std::ios::binary);
    if(!outFile)
    {
        std::cout << "Can't open File." << std::endl;
        return;
    }

    //Score loaded;
    for(const auto& hiScore : entry)
    {
        //outFile.write(reinterpret_cast<char*>(&loaded), sizeof(loaded))
        outFile << hiScore.name << " " << hiScore.score << std::endl;
    }

    outFile.close();
}
int HighScore::Least(){
    loadHighScore();
    int len = entry.size();
    if(len==3)
        return entry[2].score;
    else
        return 0;
    return 0;
}
std::string HighScore::StringValue(){
    std::string val = "";
    int i;
    loadHighScore();
    for(i=0; i<entry.size();i++){
        val += entry[i].name + " " + std::to_string(entry[i].score) + "\n";
    }
    for(i=i; i<3;i++){
        val += "--- 0\n";
    }
    return val;
}
