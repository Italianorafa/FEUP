#include <iostream>
#include <string>
using namespace std;

int main() {

    string str1, str2, str3;
    

    cout<<"Insira a primeira string: ";
    cin>>str1;

    cout<<"Insira a segunda string: ";
    cin>>str2;

    str3 = str1 + str2;
    cout<<"Concatenadas: "<<str3<<endl;

    cout<<"O tamanho da string é "<<str3.length()<<endl;

    cout<<"Segundo char: "<< str3[1]<<endl;

}  
