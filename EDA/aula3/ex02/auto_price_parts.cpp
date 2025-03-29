#include <iostream>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <string>




using namespace std;

int print_vec_componentes(vector<string> vec_comp)
{
    int size=vec_comp.size();
   
   for ( int i=0; i<size; i++ )
    {
        cout << vec_comp[i]<< endl;
    } 

    return 0;

}

int print_vec_custos(vector<float> vec_custos)
{
    int size=vec_custos.size();
   
   for ( int i=0; i<size; i++ )
    {
        cout << vec_custos[i]<< endl;
    } 

    return 0;

}

/*
 *Lê um ficheiro texto em que o parametro de entrada f é o nome do ficheiro
 * coloca informação referente aos nomes das peças num vetor.
**/

vector<string> cria_vet_componentes(string f)
{
    ifstream file(f);
    string linha;
    int numlinha=1;
    vector<string> nomes;
    if(file.good()){
        while(getline(file,linha)){
            if(numlinha%2 != 0){
                nomes.push_back(linha);
            }
            numlinha++;
        }
    }
  
    return nomes;

}

/**
 * Lê um ficheiro texto em que o parametro de entrada f é o nome do ficheiro
 * coloca informação referente aos respectivos valores das peças noutro vetor.
**/

vector<float> cria_vet_custos(string f)
{
    ifstream file(f);
    string linha;
    int numlinha=1;
    vector<float> precos;
    if(file.good()){
        while(getline(file,linha)){
            if(numlinha%2==0){
                precos.push_back(stof(linha));
            }
            numlinha++;
        }
    }
    return precos;
   
}

/**
 * Apresenta no ecran o preço da peça str_componente.
 * Retorna 0 se conseguiu ou -1 se não conseguiu.
**/

int custo_componente(string str_componente, vector<string> vec_componentes, vector<float> vec_custos){
    int size1 = vec_componentes.size(), i=0;
    while(str_componente != vec_componentes[i]){
        i++;
        if(i == size1){
            return -1;
        }
    }
    cout<<"O preço do componente "<< vec_componentes[i]<< "é: "<< vec_custos[i]<<endl;
    return 0;
    
}

/**Test code. Do not change**/

int main() {

    vector<string> vec_compon;
    vector<float> vec_custos;
    int result;
   
    vec_compon = cria_vet_componentes("auto_price_table.txt");
    print_vec_componentes(vec_compon);
    vec_custos = cria_vet_custos("auto_price_table.txt");
    print_vec_custos(vec_custos);
    result = custo_componente("Jante", vec_compon, vec_custos);
    cout << "Return de Jante é: " << result << endl;
    result = custo_componente("Retrovisor", vec_compon, vec_custos);
    cout << "Return de Retrovisor é: " << result << endl;
    result = custo_componente("Roda", vec_compon, vec_custos);
    cout << "Return de Roda é: " << result << endl;
    result = custo_componente("Vidro Traseiro", vec_compon, vec_custos);
    cout << "Return de Vidro traseiro é: " << result << endl; 
    
    return 0;
}