#include <iostream> 
using namespace std; 
 
//  
int function1(int (&arr)[5], double& x) { 
    int y = 0; 
    // inicializa uma variável y com o valor 0
    for (int i = 0; i < 5; ++i) { 
        y += arr[i]; 
    } 
    // armazena em y a soma de todos os elementos do array
    x = y / 5.0; 
    return y; 
} 
 
int main() { 
    int numeros[5] = {1, 2, 3, 4, 5}; 
    double a; 
    int b; 
 
    // armazena o resultado da média do array, obtido na função, na variavel b, de formato int
    b=function1(numeros, a); 
 
    cout << "Resultado 1 dos elementos: " << b << endl; 
    cout << "Resultado 2 dos elementos: " << a << endl; 
 
    return 0; 
}