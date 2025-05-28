#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


class Car{
    private:
        string brand;
        string model;
        float price;
        vector<string> colors;
    public:
        Car(string brand, string model, float price);
        string getBrand() const;
        string getModel() const;
        float getPrice() const;
        vector<string> getColors() const;
        void setPrice(float euros);
        void addColors(string color);
};


Car::Car(string brand, string model, float price){
    Car::brand = brand;
    Car::model = model;
    Car::price = price;
}

string Car::getBrand() const{
    return brand;
}

string Car::getModel() const{
    return model;
}


float Car::getPrice() const{
    return price;
}

vector<string> Car::getColors() const{
    return colors;
}


void Car::setPrice(float euros) {
    if(euros>=0) price = euros;
}
void Car::addColors(string color){
    colors.push_back(color);
}



void print_vector( vector<string> vec, string sep=" ")
{
    for(auto elem : vec)
    {
        cout<<elem<< sep;
    }
    cout << endl;
  
}

int main()
{
   
    string brand= "Fiat";
    string model= "500"; 
    float price = 20540; 
    Car c1(brand, model,price);

    cout << "O atributo brand é " << c1.getBrand() << endl; 
    cout << "O atributo model é " << c1.getModel() << endl;
    cout << "O atributo price é " << c1.getPrice() << endl;
    cout << "O tamanho do atributo colors é " << c1.getColors().size() << endl;

   c1.setPrice(25900);
    cout << "O atributo price é " << c1.getPrice() << endl;

    c1.addColors("Preto"); 
    cout << "Os elementos do atributo colors são:";
    print_vector(c1.getColors());  

}