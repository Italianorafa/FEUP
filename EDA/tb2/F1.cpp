#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <utility>
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

int Driver::addNumber(int num)
{
    if (num<1 || num>199) return -1;
    vector<int>::iterator it;
    it=find(numbers.begin(),numbers.end(),num);
    if (it!=numbers.end()) {
        return 1;
    }
    numbers.push_back(num);
    return 0;
}


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


int Constructor::addDriver(int driveId, int year, DriverManagement &driverManager)
{
   
    if (year<1900 || year>2025 ) return -1;

    vector<Driver*>::iterator it;
    vector<Driver*> vDriver=driverManager.getVectorDrivers();
    Driver* driver;
    bool existDriver=false;
    for (size_t i=0;i<vDriver.size();i++) {
      if(vDriver[i]->getDriverId()==driveId) {
        existDriver=true;
        driver=vDriver[i];
      }

    }
    if (existDriver) {
    int b;
    int e;
    for ( size_t i=0;i<Drivers.size(); i++){
        if (Drivers[i]->driver==driver) {
            b=Drivers[i]->begin;
            e=Drivers[i]->end;
            if (year>=b && year<=e) return 1;
            if (year==e+1) {
                Drivers[i]->end=year;
                return 0;
            } 
        }
        
    
    }
    DriCons *newDriCons=new DriCons(year,year,driver) ;
    Drivers.push_back(newDriCons);
    return 0;
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


void Driver::displayDriverInfo(ostream& os) const
{

    os << "Displaying driver info:" << endl;
    os << "-----DriverId: " << driverId << endl;
    os << "-----Code: " << code << endl;
    os << "-----Name: " << name << endl;
    os << "-----used numbers: " ;
    for (size_t i = 0; i < numbers.size()-1; ++i) {
        os  << numbers[i] << " " ;
    }
    os  << numbers[numbers.size()-1]<< endl;
    os << "-----Date of birth: " << dateOfBirth << endl;
    os << "-----Country: " << nationality;
   
}



Circuit:: Circuit(int circuitI, string nam, string locat, string  countr, int al):  circuitId(circuitI), name(nam), location(locat), country(countr), alt(al) {};

int Circuit::getCircuitId() const { return circuitId; }

string Circuit::getName() const { return name; }

string Circuit::getLocation() const { return location; }

string Circuit::getCountry() const { return country; }

int Circuit::getAlt() const { return alt; }

void Circuit::displayCircuitInfo(ostream& os) const
{

    os << "Displaying circuit info:" << endl;
    os << "-----CircuitId: " << circuitId << endl;
    os << "-----Name: " << name << endl;
    os << "-----Location: " << location << endl;
    os << "-----Country: " << country << endl;
    os << "-----Altitude: " << alt <<" metros"<< endl;
   
}


CircuitManagement::CircuitManagement(){ listCircuits.clear();};
CircuitManagement::~CircuitManagement(){
    while(listCircuits.size()!=0)
       {

	  	    Circuit* cir=listCircuits.back();
            listCircuits.pop_back();
            delete (cir);
       
                
       } 
    }


list<Circuit*> CircuitManagement::getListCircuits() const { return listCircuits; }

int CircuitManagement::circuitInsert(Circuit* circuit)
{
    if (circuit==nullptr) return -1;
    for (auto it = listCircuits.begin(); it != listCircuits.end(); ++it) {
        if ((*it) == circuit) {
            return 1;
        }
    }
    listCircuits.push_back(circuit);
    return -1; 
}

int CircuitManagement::circuitDelete(int circuitId)
{
    for (auto it = listCircuits.begin(); it != listCircuits.end(); ++it) {
        if ((*it)->getCircuitId() == circuitId) {
            delete *it; 
            listCircuits.erase(it); 
            return 0; 
        }
    }
    return -1; 
}




int ConstructorManagement::updateConstructorDrivers(string filename, DriverManagement& manager)
{
    ifstream file(filename);
   
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return -1;
    }

    string line;
    bool existConstructor=false;
    Constructor* construct;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        int constrId, driId,year;
        string ci,di,ye;
        
        getline(ss, ci, ';');
        getline(ss, di, ';');
        getline(ss, ye, ';');
       
        constrId = stoi(ci);
        driId = stoi(di);
        year = stoi(ye);
        existConstructor=false;
        for ( size_t i=0; i<vectorConstructores.size();i++) {
            if (vectorConstructores[i]->getConstructorId()==constrId) {
                existConstructor=true;
                construct=vectorConstructores[i];
            }
        }
        if (existConstructor==true) {
            
            construct->addDriver(driId,year,manager);
        }

      
    }
    file.close();
   
    return 0;
}


vector<string> ConstructorManagement::DriversAndConstructorsOfOneYear(int year,vector<string> &vConstr) {
    vector<string> vDriver;
    if (year<1900 || year>2025 ) return vDriver;
    vector<string>::iterator it;
    vector<DriCons*> dC;
    for (size_t i=0;i<vectorConstructores.size();i++){
        dC=vectorConstructores[i]->getDrivers();
        for (size_t j=0;j<dC.size();j++) {
            if (year>=dC[j]->begin && year<=dC[j]->end) {
                it=find(vDriver.begin(),vDriver.end(),dC[j]->driver->getName());
                if (it==vDriver.end()) {
                    vDriver.push_back(dC[j]->driver->getName());
                }
                it=find(vConstr.begin(),vConstr.end(),vectorConstructores[i]->getName());
                if (it==vConstr.end()) {
                    vConstr.push_back(vectorConstructores[i]->getName());
                }

            }

        }

    }
    sort(vConstr.begin(),vConstr.end());
    sort(vDriver.begin(),vDriver.end());
    return vDriver;
}


Race:: Race(int raceI, int seas, int roun, Circuit*  circui, string dat):  raceId(raceI), season(seas), round(roun), circuit(circui), date(dat) {};

int Race::getRaceId() const { return raceId; }

int Race::getSeason() const { return season; }

int Race::getRound() const { return round; }

Circuit* Race::getCircuit() const { return circuit; }

string Race::getDate() const { return date; }

list<DriResult*>  Race::getListRaceResults() const { return listRaceResults; }

int Race::addDriverResult(DriResult *driveR, DriverManagement &driManager) {
    if (driveR==nullptr) 
    return -1;
    vector<Driver*> vd=driManager.getVectorDrivers();
    bool exist=false;
   
    for (size_t i=0;i<vd.size();i++){
        if (vd[i]->getDriverId()==driveR->drive->getDriverId()) {
            exist=true;
           
            break;
        }
    }
    
    if (!exist) return -1;
    for (auto it=listRaceResults.begin();it!=listRaceResults.end();it++) {
        if ((*it)->drive==driveR->drive) {
           
            return 1;

        }
    }
    listRaceResults.push_back(driveR);
    return 0;
}



void Race::displayRaceInfo(ostream& os) const
{

    os << "Displaying race info:" << endl;
    os << "-----RaceId: " << raceId << endl;
    os << "-----Season: " << season << endl;
    os << "-----Round: " << round << endl;
    os << "-----CircuitName: " << circuit->getName() << endl;
    os << "-----Date: " << date << endl;
   
}


RaceManagement::RaceManagement(){ listRaces.clear();};
RaceManagement::~RaceManagement(){
    while(listRaces.size()!=0)
       {

	  	    Race* rac=listRaces.back();
              listRaces.pop_back();
            delete (rac);
       
                
       } 
    }


list<Race*> RaceManagement::getListRaces() const { return listRaces; }

int RaceManagement::raceInsert(Race* race)
{
    if (race==nullptr) return -1;
    for (auto it = listRaces.begin(); it != listRaces.end(); ++it) {
        if ((*it) == race) {
            return 1;
        }
    }
    listRaces.push_back(race);
    return -1; 
}

int RaceManagement::raceDelete(int raceId)
{
    for (auto it = listRaces.begin(); it != listRaces.end(); ++it) {
        if ((*it)->getRaceId() == raceId) {
            delete *it; 
            listRaces.erase(it); 
            return 0; 
        }
    }
    return -1; 
}



/**************************/
/*     A implementar      */
/**************************/





int RaceManagement::numberRacePerSeason(int nRaces) {
    int num = 0;
    if(nRaces<0){
        return -1;
    }
    vector <int> anos(6,0);
    for(auto aux1 : getListRaces()){
        if(aux1->getSeason() - 2004 < 0 && aux1->getSeason() - 2004 > 5){
            return -1;
        }
        anos[(aux1->getSeason() - 2004)]++;
    }

    for(int i=0; i<7; i++){
        if(anos[i] == nRaces){
            num++;
        }
    }
    return num;
}

queue<string> RaceManagement::seasonGrandPrix(int year) {
    auto corridas = getListRaces();
    queue <string> ordenada;
    if(year<2004 || year>2009){
        for(auto aux1 : getListRaces()){
            if(aux1->getSeason() != year){
                ordenada.push("-1");
                return ordenada;
            }
        }
    }
    corridas.sort([] (Race *r1, Race *r2){
        return r1->getRound() < r2->getRound();
    });

    for(auto aux2 : corridas){
       if(aux2->getSeason() == year){
        ordenada.push(aux2->getCircuit()->getName());
       }
    }
    return ordenada;
}

int RaceManagement::uploadFromFile(string filename, DriverManagement &driManager, ConstructorManagement &consManager) {
    ifstream f(filename);
    string linha;
    Driver *auxD = nullptr;
    Constructor *auxC =nullptr;
    Race *auxR = nullptr;
    int i=0;
    if(!f.good()){
        return -1;
    }
    while(getline(f,linha)){
        string srId, sdId, scId, snum, sgrid, spos, slaps, sstats;
        int rId, dId, cId, num, grid, pos, laps, stats;
        stringstream ss(linha);
        getline(ss, srId, ';');
        rId = stoi(srId);
        getline(ss, sdId, ';');
        dId = stoi(sdId);
        getline(ss, scId, ';');
        cId = stoi(scId);
        getline(ss, snum, ';');
        num = stoi(snum);
        getline(ss, sgrid, ';');
        grid = stoi(sgrid);
        getline(ss, spos, ';');
        pos = stoi(spos);
        getline(ss, slaps, ';');
        laps = stoi(slaps);
        getline(ss, sstats);
        stats = stoi(sstats);
        for(Race *aux1 : getListRaces()){
            if(aux1->getRaceId() == rId){
                auxR = aux1;
                for(auto *aux2 : driManager.getVectorDrivers()){
                    if(aux2-> getDriverId() == dId){
                        auxD = aux2;
                        for(auto *aux3 : consManager.getVectorConstructores()){
                            if(aux3 -> getConstructorId() == cId){
                                auxC = aux3;
                                if(grid>0 && laps>=0){   
                                    DriResult *update = new DriResult(aux2, aux3, num, grid, pos, laps, stats);
                                    aux1->addDriverResult(update, driManager);
                                }
                            }
                        }
                    }
                }
            }
            
        }
        i++;
    }
    if(auxD == nullptr || auxC == nullptr || auxR == nullptr){
        return -1;
    }
    return i;
}

string RaceManagement::driverStatus(string status, int &num) {
    vector<pair<string,int>> ocorrencia;
    bool encontrado = false;

    for(auto aux1 : getListRaces()){
        for(auto aux2 : aux1->getListRaceResults()){
            if(vStauts[aux2->status] == status){
                if(!ocorrencia.empty()){
                    
                    for(auto i=ocorrencia.begin(); i!=ocorrencia.end(); i++){
                        if(i->first == aux2->drive->getName()){
                            i->second++;
                            encontrado = true;
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    if(!encontrado){
                        ocorrencia.push_back(make_pair(aux2->drive->getName(), 1));
                    }
                }
                else{
                    ocorrencia.push_back(make_pair(aux2->drive->getName(), 1));
                }
            }
        }
    }

    sort(ocorrencia.begin(), ocorrencia.end(), [](auto o1, auto o2){
        return o1.second >= o2.second;
    });


    if(ocorrencia[0].second == ocorrencia[1].second){
        if(ocorrencia[0].first < ocorrencia[1].first){
            pair<string, int> auxT = ocorrencia[0];
            ocorrencia[0] = ocorrencia[1];
            ocorrencia[1] = auxT;
        }
    }

    num = ocorrencia[0].second;
    return ocorrencia[0].first;
}

int RaceManagement::scoreCareer (int driveI, DriverManagement &drivManager, int &ngrids) {
    int points=0, poles=0;
    auto drives = drivManager.getVectorDrivers();
    bool encontrado = false;
    auto e = find_if(drives.begin(), drives.end(), [=](const Driver* id){
        return id->getDriverId() == driveI;
    });
    if(e != drives.end()){
        encontrado = true;
    }
    if(encontrado){
        for(Race *aux1 : getListRaces()){
            int ano = aux1->getSeason();
            if (ano<1950 || ano>2025){
                return -1;
            }
            for(DriResult *aux2 : aux1->getListRaceResults()){
                if(driveI == aux2->drive->getDriverId()){
                    auto pos = aux2->position;
                    if(aux2->grid == 1){
                        poles++;
                    }
                    if(ano>=1950 && ano<1960){
                        if(pos == 1) points += 8;                           
                        else if(pos == 2) points += 6;
                        else if(pos==3) points += 4;
                        else if(pos ==4) points += 3;
                        else if(pos ==5) points += 2;    
                        else break;
                    }
                    else if(ano>=1960 && ano<1991){
                        if(pos == 1) points += 9;                           
                        else if(pos == 2) points += 6;
                        else if(pos==3) points += 4;
                        else if(pos ==4) points += 3;
                        else if(pos ==5) points += 2;
                        else if(pos==6) points += 1;  
                        else break;
                    }
                    else if(ano>=1991 && ano<2003){
                        if(pos == 1) points += 10;                           
                        else if(pos == 2) points += 6;
                        else if(pos==3) points += 4;
                        else if(pos ==4) points += 3;
                        else if(pos ==5) points += 2;
                        else if(pos==6) points += 1;  
                        else break;
                    }
                    else if(ano>=2003 && ano<2010){
                        if(pos == 1) points += 10;                           
                        else if(pos == 2) points += 8;
                        else if(pos==3) points += 6;
                        else if(pos ==4) points += 5;
                        else if(pos ==5) points += 4;
                        else if(pos==6) points += 3;
                        else if(pos==7) points += 2;
                        else if(pos==8) points += 1; 
                        else break;
                    }
                    else{
                        if(pos == 1) points += 25;                           
                        else if(pos == 2) points += 18;
                        else if(pos==3) points += 15;
                        else if(pos ==4) points += 12;
                        else if(pos ==5) points += 10;
                        else if(pos==6) points += 8;
                        else if(pos==7) points += 6;
                        else if(pos==8) points += 4;
                        else if(pos==9) points += 2;
                        else if(pos==10) points += 1; 
                        else break;
                    }
                }
            }
        }
    }
    ngrids = poles;
    return points;
}