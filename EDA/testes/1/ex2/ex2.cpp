#include <iostream>
#include <vector>

using namespace std;


vector<int> rangeOfValues(vector<int>& v, int n1, int n2){
    vector<int> valores = v;
    if(n1 < n2){
        return {};
    }
    for(int i=0; i<=v.size(); i++){
        if(valores[i]<n1 || valores[i]>n2){
            valores.erase(v.begin() + i);
        }
    }
    return valores;
}


int insert_pos(vector<int>& v, int pos, int value, int rep){
    if(pos<0 || rep<0){
        return -1;
    }
    else{
        v.insert(v.begin() + pos, rep, value);
    }
    return 0;
}

// Utility function to print the vector
void print_vec(vector<int>& v){
    cout << "Return Value:  " << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl; 
}



int main(){
    
    //Teste 1
    vector<int> numbers1{5,12,65,34,86,24,27,78};
    vector<int> res1;
    res1=rangeOfValues(numbers1, 10, 30);
    print_vec(res1);

    //teste 2
    vector<int> numbers2{};
    vector<int> res2;
    res2=rangeOfValues(numbers2, 10, 30);
    if (res2.empty())
    {cout << "Return Value: Ok, is empty"<< endl;} 
    else 
    {cout << "Return Value: not Ok, not empty"<<endl;} 

    
    vector<int> numbers3{5,12,65,34,86,24,27,78};
    



 
    
    //Teste 1
    cout << "Return Value: " << insert_pos(numbers1, 4, 20,1)<< endl;
    print_vec(numbers1);


    //Teste 2
    cout << "Return Value: " << insert_pos(numbers3, 1, 10,4)<< endl;
    print_vec(numbers3);

}