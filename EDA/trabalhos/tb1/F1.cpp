#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "F1.hpp"

using namespace std;

Driver:: Driver(int driverI, string cod, string nam, vector<int> numbe, string dateOfBir, string  nationali):  driverId(driverI), code(cod), name(nam), numbers(numbe), dateOfBirth(dateOfBir), nationality(nationali) {};
Driver:: Driver(int driverI, string cod, string nam,  string dateOfBir, string  nationali):  driverId(driverI), code(cod), name(nam), dateOfBirth(dateOfBir), nationality(nationali) {};

int Driver::getDriverId() const { return driverId; }

string Driver::getCode() const { return code; }

string Driver::getName() const { return name; }

vector<int> Driver::getNumbers() const { return numbers; }

string Driver::getDateOfBirth() const { return dateOfBirth; }

string Driver::getNationality() const { return nationality; }

Constructor::Constructor(int constructorId, string name, string country) : constructorId(constructorId), name(name), nationality(country) {};

int Constructor::getConstructorId() const { return constructorId; }

string Constructor::getName() const { return name; }

string Constructor::getCountry() const { return nationality; }

vector<DriCons*> Constructor::getDrivers() { return Drivers; }


int Constructor::deleteDriver(int driveId)
{
   
    for ( auto it=Drivers.begin();it!=Drivers.end(); it++){
        if ((*it)->driver->getDriverId()==driveId) {
           delete(*it);
	Drivers.erase(it);
	return 0;
            } 
        }
        
    
  
   return -1;
}



DriverManagement::DriverManagement(){ vectorDrivers.clear();};
DriverManagement::~DriverManagement(){
    while(vectorDrivers.size()!=0)
       {

	  	
            delete (vectorDrivers[vectorDrivers.size()-1]);
            vectorDrivers.pop_back();
                
       } 
    }


vector<Driver*> DriverManagement::getVectorDrivers() const { return vectorDrivers; }

int DriverManagement::driverInsert(Driver* driver)
{
    if (driver==nullptr) return -1;
    for (auto it = vectorDrivers.begin(); it != vectorDrivers.end(); ++it) {
        if ((*it) == driver) {
            return 1;
        }
    }
    vectorDrivers.push_back(driver);
    return -1; 
}

int DriverManagement::driverDelete(int driverId)
{
    for (auto it = vectorDrivers.begin(); it != vectorDrivers.end(); ++it) {
        if ((*it)->getDriverId() == driverId) {
            delete *it; 
            vectorDrivers.erase(it); 
            return 0; 
        }
    }
    return -1; // Series not found
}

ConstructorManagement::ConstructorManagement(){vectorConstructores.clear();};
ConstructorManagement::~ConstructorManagement(){
while(vectorConstructores.size()!=0)
   {   
        while(vectorConstructores[vectorConstructores.size()-1]->getDrivers().size()!=0) {
	vectorConstructores[vectorConstructores.size()-1]->deleteDriver(vectorConstructores[vectorConstructores.size()-1]->getDrivers()[0]->driver->getDriverId());

}
   
        delete (vectorConstructores[vectorConstructores.size()-1]);
        vectorConstructores.pop_back();
            
   } 
}
vector<Constructor*> ConstructorManagement::getVectorConstructores() const { return vectorConstructores; }

int ConstructorManagement::addConstrutor(Constructor* newConstructor)
{
    if(newConstructor==nullptr) return -1;
    auto it=find(vectorConstructores.begin(),vectorConstructores.end(),newConstructor);
    if (it==vectorConstructores.end()) {
        vectorConstructores.push_back(newConstructor);
        return 0;
    }
    return 1;
}

/**************************/
/*     A implementar      */
/**************************/

int Driver::addNumber(int num)
{
    int size = numbers.size();
    if (num<1 || num>199){
        return -1;
    }
    for(int i=0; i<size; i++){
        if(num == numbers[i]){
            return 1;
        }
    }
    numbers.push_back(num);
    
    return 0;
}


void Driver::displayDriverInfo(ostream& os) const
{
    cout<< "Displaying driver info: "<< endl;
    cout << "-----DriverId: "<< driverId<< endl;
    cout << "-----Code: "<< code<< endl;
    cout << "-----Name: "<< name<< endl;
    cout << "-----used numbers: ";
    for(int i=0; i<(int)numbers.size(); i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout<< "-----Date of birth: "<< dateOfBirth<< endl;
    cout<< "-----Country: "<<nationality<< endl;
   
   
}



int Constructor::addDriver(int driveId, int year, DriverManagement &driverManager)
{
   vector<Driver*> vec = driverManager.getVectorDrivers();
   Driver *auxdriver = nullptr;
   
   if(driveId<=0 || year<1950 || year>=2025){
    return -1;
   }

   for(Driver *aux1 : vec){
    if(aux1->getDriverId() == driveId){
        auxdriver = aux1;
    }
   }
   if(auxdriver == nullptr){
    return -1;
   }
    

   for(DriCons *aux2 : Drivers){
    if(aux2->driver == auxdriver){
        aux2->end = year;
        return 1;
    }
    }
    DriCons *Ndriver = new DriCons(year, year, auxdriver);

   Drivers.push_back(Ndriver);

   return 0;
}


int ConstructorManagement::updateConstructorDrivers(string filename, DriverManagement& manager)
{
    ifstream f(filename);
    string linha;
    if(!f.good()){
        return -1;
    }
    if(f.good())
    {    
        while(getline(f, linha)){
            string sconstr;
            stringstream ss(linha);
            getline(ss, sconstr, ';');
            for(Constructor *aux : vectorConstructores){
                if(stoi(sconstr) == aux -> getConstructorId()){
                    string sdrive, syear;
                    getline(ss, sdrive, ';');
                    getline(ss, syear, ';');
                    int IdD = stoi(sdrive), ano = stoi(syear);
                    aux -> addDriver(IdD, ano, manager);
                }
            }
        }
    }
    return 0;
}


vector<string> ConstructorManagement::DriversAndConstructorsOfOneYear(int year,vector<string> &vConstr) {
  
    vector<string> vecD;
    
    for(auto * aux1 : getVectorConstructores()){
        for(auto *aux2 : aux1->getDrivers()){
            if(aux2->begin <= year && aux2->end >= year){
                auto Dname = aux2->driver->getName();
                if(find(vecD.begin(), vecD.end(), Dname) == vecD.end()){
                    vecD.push_back(Dname);
                }

                auto Cname = aux1->getName();
                if(find(vConstr.begin(),vConstr.end(), Cname) == vConstr.end()){
                    vConstr.push_back(Cname);
                }
            }
        }
    }
    

    sort(vecD.begin(),vecD.end());
    sort(vConstr.begin(), vConstr.end());
    return vecD;
}
