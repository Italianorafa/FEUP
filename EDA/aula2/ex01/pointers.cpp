#include <iostream>
using namespace std;



/*
 *  calculates de square of a variable
 *  parameter: int n - number to calculate the square of
 *  return: int - calculated square valkue of n
 */

int square_by_value(int n){

    cout<<&n<<endl;

    n = n*n;
    
    cout<<n<<endl;

    return n;
}

/*
 *  calculates de square of a variable
 *  parameter: int *pN - pointer to the number to calculate the square of
 *  return: void
 */

void square_by_reference_point_args(int *pN){
    
    cout<<pN<<endl; 

    *pN = *pN*(*pN);
    
    cout<<*pN<<endl;
}


/*
 *  calculates de square of a variable
 *  parameter: int &rN - reference of the number to calculate the square of
 *  return: void
 */

void square_by_reference_ref_args(int &rN){
    cout<<&rN<<endl;

    rN = rN * rN;
    
    cout<<rN<<endl;
}







/* ---------- Test Code. Do not change ---------- */ 
int main (){ 
    int number = 8;
    cout <<  "---------- Testing the square_by_value function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;
    square_by_value(number);
    cout << "Its value in main after calling square_by_value(number) is " << number <<  endl;

    number = 8;
    cout <<  "\n\n---------- Testing the square_by_reference_point_args function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;  
    square_by_reference_point_args(&number); // Explicit referencing to pass an address
    cout << "Its value in main after calling square_by_reference_point_args(&number) is " << number <<  endl;


    number = 8;
    cout <<  "\n\n---------- Testing the square_by_reference_ref_args function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;  
    square_by_reference_ref_args(number); // Implicit referencing (without '&')
    cout << "Its value in main after calling square_by_reference_ref_args(number) is " << number <<  endl;

}