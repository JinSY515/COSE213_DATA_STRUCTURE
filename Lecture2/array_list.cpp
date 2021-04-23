#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

class Scores;
class GameEntry{
    public:
    GameEntry(const string& n="", int s=0);
    ~GameEntry();
    string GetName() const;
    int getScore() const;

    private:
    string name;
    int score;
};

class Scores{
    public:
    Scores(int maxEnt=10);
    ~Scores();

    void add(const GameEntry& e);
    GameEntry Remove(int i);

    private:
    int maxEnt;
    int numEnt;
    GameEntry *entries;
};

void Scores::add(const GameEntry& e){
    int newScore=e.getScore();
    if(numEnt == maxEnt){
        if(newScore <= entries[maxEnt-1].getScore())
        return;
    }
    else{
        numEnt++;
    }

    int i=numEnt-2;
    while(i>=0 && newScore > entries[i].getScore()){
        entries[i+1]=entries[i];
        i--;
    }
    entries[i+1]=e;
};


GameEntry Scores::Remove(int i){
    if(i<0 || i>=numEnt) return;

    GameEntry e=entries[i];

    for(int j=i+1; j<numEnt; j++){
        entries[j-1]=entries[j];
    }
    numEnt--;
    return e;
}

