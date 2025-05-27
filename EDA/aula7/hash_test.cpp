#include "hash.hpp"

void comparetime_hash(string arr1[], int size){
    //alinea D
    HashMapTable hash1(size);
    HashMapTable hash2(size);

    clock_t beg1, end1;
    double time1;

    beg1 = clock();
    for(int i = 0; i<size; i++){
        hash1.insertElement(arr1[i], 0);
    }
    hash1.search_value("Joana", 0);
    hash1.deleteElement("Luis", 0);
    end1 = clock();

    time1 = (double)(end1 - beg1) / CLOCKS_PER_SEC;
    cout<< "Time used by the first hash function is " << time1 << endl;

    clock_t beg2, end2;
    double time2;

    beg2 = clock();
    for(int i = 0; i<size; i++){
        hash1.insertElement(arr1[i], 1);
    }
    hash2.search_value("Joana", 1);
    hash2.deleteElement("Luis", 1);
    end2 = clock();

    time1 = (double)(end2 - beg2) / CLOCKS_PER_SEC;
    cout<< "Time used by the second hash function is " << time2 << endl;
}

int main(){




    // array of all the keys to be inserted in hash table
    string arr[] = {"Luis", "Miguel", "Joana", "Catarina", "Afonso", "Luana", "Carlos", "leandro"};
    int n = sizeof(arr)/sizeof(arr[0]);
  //  int n=arr->size();

    // table_size of hash table as 6
    HashMapTable ht(n);
    for (int i = 0; i< n; i++)
    ht.insertElement(arr[i], 0);
   

    // deleting element Miguel from the hash table
    ht.deleteElement("Miguel",0);
    // displaying the final data of hash table
    ht.displayHashTable(); 

    
    //testing search value
    string value = "Joana";
    cout<< "Searching for value "<< value << " and returning position "<< ht.search_value(value, 0) << endl;
    value = "João"; 
    cout<< "Searching for value "<< value << " and returning position "<< ht.search_value(value, 0) << endl;
    
    //testing new hash function

    // table_size of hash table as 6
    HashMapTable ht2(n);
    for (int i = 0; i< n; i++)
    ht2.insertElement(arr[i], 1);
    // deleting element 34 from the hash table
    ht2.deleteElement("Luis",1);
    // displaying the final data of hash table
    ht2.displayHashTable();
    
        //testing search value
    value = "Joana";
    cout<< "Searching for value "<< value << " and returning position "<< ht2.search_value(value, 1) << endl;
    value = "João"; 
    cout<< "Searching for value "<< value << " and returning position "<< ht2.search_value(value, 1) << endl;
    
    //testing times for both hash functions
    comparetime_hash(arr, n);



    //testing count chars
    char c = 'b';
    cout<< "Searching for char "<< c << " and found "<< ht2.count_words_starting_char(c) << " words beginning with it"<<  endl;
    c = 'c';
    cout<< "Searching for char "<< c << " and found "<< ht2.count_words_starting_char(c) << " words beginning with it"<<  endl;
    
    
    return 0;


}