#include <iostream>

using namespace std;

void sumOfIntegers()
{
    int n, sum=0;
    cout<<"Insria um inteiro: ";
    cin>>n;
    
    while(n!=0){
        sum += n;
        n--;
    }
  
    cout<<"Resultado: "<<sum<<"\n";
   
}

/**Test code. Do not change**/

int main() {

   sumOfIntegers();

    return 0;
}  
