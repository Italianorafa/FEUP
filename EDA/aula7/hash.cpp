#include "hash.hpp"



HashMapTable::HashMapTable(int ts){ // Constructor -- creating the hash table
    this->table_size = ts;
    table = new list<string>[table_size];
}

int HashMapTable::hashFunction(string key) { // HASH function
    return (key.length() % table_size);
}

int HashMapTable::hashFunctionkrm(string key){ // New hash function
    //alinea A
    if(key.empty()) return 7 % table_size; // caso base

    char last = key[key.size() - 1]; // ultimo caractere da key
    string subKey = key.substr(0, key.size() -1); // sub-string para recursao
    
    return (hashFunctionkrm(subKey) + last) % table_size;
}

void HashMapTable::insertElement(string key, int func){ // insert - push the keys in hash table
    if(func == 0){
        int index = hashFunction(key);
        table[index].push_back(key);

    } else if (func == 1){
        int index = hashFunctionkrm(key);
        table[index].push_back(key);
    }

    
}


int HashMapTable::search_value(string key, int func){ 
    // alinea B
    int pos = (func == 0) ? hashFunction(key) : hashFunctionkrm(key);

    for(auto &chave : table[pos]){
        if(chave == key){
            return pos;
        }
    }
    return -1;
}


void HashMapTable::deleteElement(string key, int func){ // delete element from the hash table
    //alinea C
    int pos = (func==0) ? hashFunction(key) : hashFunctionkrm(key);

    for(auto it = table[pos].begin(); it != table[pos].end(); it++){
        if((*it) == key){
            it = table[pos].erase(it);
            break;
        }
    }
   
}


void HashMapTable::displayHashTable() {
    //for (int i = 0; i<table_size; i++) {
    for (int i = 0; i<table_size; i++) {
        cout<<i;
        // traversing at the recent/ current index
        for (auto j : table[i])
            cout<< " ==> " << j;
            cout<<endl;
    }
    
}


int HashMapTable::count_words_starting_char(char c){
    //alinea E
    int contagem = 0;
    char c_low = tolower(c);

    for(int i=0; i<table_size; i++){
        for(auto &key : table[i]){
            if(!key.empty() && c_low == tolower(key[0])){
                contagem++;
            }
        }
    }

    return contagem;
} 





