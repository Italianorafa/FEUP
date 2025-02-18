#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


/**
 *  reads and prints the file f
 *  param: string f is the name of the file
 *  return: -1 if error, 0 if everything ok 
 */
void print_file(string f){
    string linha;
    ifstream file(f);
    while(getline(file,linha)){
        cout<<linha<<endl;
    }
    file.close();
}

/**
 *  counts and prints the number of chars in file f
 *  param: string f is the name of the file
 *  return: -1 if error, 0 if everything ok 
 */
void count_characters(string f) {
    string linha;
    int chars=0;
    ifstream file(f);
    while(getline(file,linha)){
        for(int i=0; i<linha.length(); i++){
            chars++;
        }
    }
    cout<<"O número total de caracteres é: "<<chars<<'\n';
}


/**Test code. Do not change**/

int main() {
	print_file("grocery_list.txt");
    count_characters("grocery_list.txt");
    return 0;
}

