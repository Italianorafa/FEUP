#include <iostream>
#include <fstream>
#include <algorithm>
#include "RankingNomes.hpp"
using namespace std;

RankingNomes::RankingNomes(string ficheiro, int num_pos)
{
  ifstream names(ficheiro);
  int n=0;
  while(n<num_pos){
    string linha;
    getline(names, linha);
    nomes.push_back(linha);
    n++;
  }

}

void RankingNomes::Imprime() const
{
  int n=1;
  for(auto it=nomes.begin(); it!=nomes.end(); it++){
    cout<<"pos "<<n<<" -> "<< *it;
    n++;
  }
  
};

int RankingNomes::Insere(string nome, int posicao)
{
  // Alínea c)
  return 0;

};

int RankingNomes::Remove(int posicao)
{
  // Alínea d)

  return 0;

};

int RankingNomes::Promove(int pos, int numero_pos)
{
  // Alínea e)

  return 0;
};

int RankingNomes::Despromove(int pos, int numero_pos)
{
  // Alínea f)
  return 0;
};



