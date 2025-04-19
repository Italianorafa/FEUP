#include <iostream>
#include <vector>

using namespace std;


int insert_several(vector<int>& v, int n){
    int num = 2;
    if(n<2){
        return -1;
    }
    else{
        while(num<=n){
            v.push_back(num);
            num += 2;
        }
    }
    return 0;
}


int insert_pos(vector<int>& v, int pos, int value){
    if(pos<0 || pos> v.size()){
        return -1;
    }
    else{
        v.insert(v.begin() + pos , value);
    }
    return 0;
}

// Utility function to print the vector
void print_vec(vector<int>& v){
    cout << "Vector elements: " << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl; 
}



int main(){
    

    vector<int> numbers;
    cout << "Return Value: " << insert_several(numbers,10) << endl;
    print_vec(numbers);

    int pos = 3;
    int value = 4;
    cout << "Return Value: " << insert_pos(numbers, pos, value)<< endl;
    print_vec(numbers);


}