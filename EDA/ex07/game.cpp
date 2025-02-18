#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
Game to match a number between 1 and 100

tip: use rand() to generate random numbers, remember that rand() generates numbers 
between 0 and RAND_MAX. To initialize rand, use srand (time(NULL));
*/


int main() {
    
    srand(time(NULL));
    int num = 1+rand()%100, guess, cont=1;
    cout<<"Adivinhe o número: ";
    cin>>guess;
    while(guess!=num){
        if (guess>num){
            cout<<"O número procurado é menor.\n";
        }
        else{
            cout<<"O número procurado é maior.\n";
        }
        cout<<"Insira outro número: ";
        cin>>guess;
        cont++;
    }
    if (cont>1){
    cout<<"Acertou em "<< cont <<" tentativas\n";
    }
    else{
        cout<<"Acertou em "<< cont << "tentativa\n";
    }
    
    return 0;
}  
