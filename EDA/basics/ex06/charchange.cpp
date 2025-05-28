#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    char c_old, cnew;
    
    cout<<"Insira a string: ";
    cin>>str;
    cout<< "Insira o caractere que deseja alterar: ";
    cin>>c_old;
    cout<<"Insira o novo caractere: ";
    cin>>cnew;

    for(int i=0; i<str.length(); i++){
        if(str[i] == c_old)
        str[i] = cnew;
    }
    cout<<"String modificada: "<<str<<endl;
    return 0;
}