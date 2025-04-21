#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct Player {
    int number;
    string name;
    double pointsPerGame;
};

void insertFromCSV(const string&, vector<Player>&);
void printContent(const vector<Player>& );

int main() {
    vector<Player> players;
    insertFromCSV("players.txt", players);
    printContent(players);
    return 0;
}

void insertFromCSV(const string& filename, vector<Player>& players)
{
    ifstream f(filename);
    string linha, name, snumber, spoints;
    int number;
    double points;
    if(f.good())
    {   
        while(getline(f, linha)){
            stringstream ss = (stringstream) linha;
            getline(ss, snumber, ',');
            number = stoi(snumber);
            getline(ss, name, ',');
            getline(ss, spoints);
            points = stod(spoints);
            cout<<"Player "<< number << " was read"<<endl;
            players.push_back({number, name, points});
        }
    }
    
}

void printContent(const vector<Player>& players)
{    
    int nPlayers=0;
    double tPoints=0;

    for(Player p : players){
        cout<< p.number << ": "<< p.name << " Points = "<< p.pointsPerGame<< endl;
        nPlayers ++;
        tPoints += p.pointsPerGame;
    }
    double media = tPoints/nPlayers;

    cout<<"Numbers of players: "<<nPlayers<<endl;
    cout<<"Avarage points in the match: "<<media<<endl;
}