#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


class Book{
    private:
        int isbn;
        int quantity;
        bool avaliable;
        string title;
        string author;
        float price;
        vector<string> genres;
    public:
        //constructors
        Book(int ISNB, int quantity, string title, string author, float price);
        //getters
        int getISBN() const;
        int getQuantity() const;
        bool getAvailable() const;
        string getTitle() const;
        string getAuthor() const;
        float getPrice() const;
        vector<string> getGenres() const;
        //setters
        void setPrice(float euros);
        void addGenres(string genero);
};


Book::Book(int ISBN, int quantity, string title, string author, float price){
    isbn = ISBN;
    Book::title = title;
    Book::author = author;
    if(price<0) Book::price = 0;
    else Book::price =price;

    if(quantity<0) Book::quantity=0;
    else{
        Book::quantity = quantity;
        avaliable = true;
    }
}

int Book::getISBN() const{
    return isbn;
}

int Book::getQuantity() const{
    return quantity;
}

bool Book::getAvailable() const{
    return avaliable;
}

string Book::getTitle() const{
    return title;
}

string Book::getAuthor() const{
    return author;
}

float Book::getPrice() const{
    return price;
}

vector<string> Book::getGenres() const{
    return genres;
}


void Book::setPrice(float euros){
   if(euros>=0){
    price = euros;
   }
}
void Book::addGenres(string genrs){
    genres.push_back(genrs);
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
   
    cout << "Beginning Tests\n\n" << endl;

    int ISBN = 1236574; 
    int quantity = 78; 
    string title = "The Hobbit";
    string author = "J. R. R. Tolkien"; 
    float price = 9.98; 
    Book b1(ISBN,quantity,title,author,price);

    cout << "O atributo ISBN é " << b1.getISBN() << endl;
    cout << "O atributo availability é " << b1.getAvailable() << endl;
    cout << "O atributo quantity é " << b1.getQuantity() << endl;
    cout << "O atributo title é " << b1.getTitle() << endl; 
    cout << "O atributo author é " << b1.getAuthor() << endl;
    cout << "O atributo price é " << b1.getPrice() << endl;
    cout << "O tamanho do atributo genres é " << b1.getGenres().size() << endl;

    //Setter
    b1.setPrice(7.2);
      cout << "O atributo price é " << b1.getPrice() << endl;

    //Other methods
    b1.addGenres("High Fantasy"); 
    cout << "Os elementos do atributo genres são:";
    print_vector(b1.getGenres()); 





}