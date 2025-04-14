#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "F1.hpp"

using namespace std;
vector<Qualifying> importQualifying (string filename, DriverManagement &manager);

int verifica_moreTimesNumber(RaceManagement &manager)
{
    int er = 0;
    int con=0;
    string res=manager.moreTimesNumber(1,con);
   
    if (res!="Ferrari")
    {
        cout << "...verifica_moreTimesNumber ( numero 1 ): Construtor (="<<res<<") e' diferente do esperado (=Ferrari) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_moreTimesNumber ( numero 1 ):  Construtor (="<<res<<" (ok)" << endl;
    }
       
    if (con!=54)
    {
        cout << "...verifica_moreTimesNumber ( numero 1  ): A "<<res<<" ganhou (="<<con<<") e' diferente do esperado (=11) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_moreTimesNumber ( numero 1  ):  A "<<res<<" ganhou (="<<con<<") vezes  (ok)" << endl;
    

   
    return er;
}



int verifica_startingGrid(RaceManagement &racmanager, DriverManagement &drivermanager)
{
    int er = 0;
  

vector<Qualifying> vq;
priority_queue<Qualifying,vector<Qualifying>, greater<Qualifying>> pq;
vq=importQualifying ("qualifying.csv", drivermanager);

 pq=racmanager.startingGrid(vq);


    
    string str="",strtotal="",str1;

    size_t res=pq.size();
  
 
    if (!strtotal.empty()) { strtotal.pop_back(); strtotal.pop_back();}

    /*Teste 1*/
   if (res!=22)
    {
        cout << "...verifica_startingGrid(época 2004): Numero de pilotos (="<<res<<") e' diferente do esperado (=22) (ERRO)"<< endl;
           er++;
    }
    else
        cout << "...verifica_startingGrid: Numero de pilotos (="<<res<<") (ok) "<< endl;

    /*Teste 2*/
    str="1-Heikki Kovalainen:85.664000 2-Nick Heidfeld:85.960000 3-Felipe Massa:85.999400 4-Robert Kubica:86.103000 5-Kimi Räikkönen:86.140000 6-Nico Rosberg:86.295000 7-Rubens Barrichello:86.369000 8-David Coulthard:86.381000 9-Jarno Trulli:86.427000 10-Lewis Hamilton:86.572000 11-Sebastian Vettel:86.702000 12-Jenson Button:86.712000 13-Kazuki Nakajima:86.891000 14-Fernando Alonso:86.907000 15-Mark Webber:86.914000 16-Timo Glock:86.919000 17-Giancarlo Fisichella:87.207000 18-Sébastien Bourdais:87.446000 19-Adrian Sutil:87.859000 20-Takuma Sato:88.208000 21-Nelson Piquet Jr.:88.330000 22-Anthony Davidson:89.059000"; 
    int k=1;
    while(!pq.empty())
    {
            strtotal += to_string(k)+"-"+pq.top().driver->getName()+":"+to_string(pq.top().timeLap)+" ";
            pq.pop();
            k++;
    }
    
    if (!strtotal.empty()) strtotal.pop_back();
   if (str!=strtotal)
   {
       cout << "...verifica_startingGrid: Grelha (="<<strtotal<<") e' diferente do esperado (="<<str<<") (ERRO)"<< endl;
          er++;
   }
   else
       cout << "...verifica_startingGrid: Grelha (="<<strtotal<<") (ok) "<< endl<< strtotal<<endl;


    return er;
}
   



int verifica_insertNode(RaceManagementTree &racManagerTree, RaceManagement &racManager)
{
    int er = 0;
  


    list<Race*> lRaces=racManager.getListRaces();
    auto it=lRaces.begin();
    for (size_t i=0;i<lRaces.size();i++) {
         
         racManagerTree.addRace(*it);
         it++;
    }
    NodeRace* aux=racManagerTree.getRoot();
 
    if (aux!=nullptr) {
    if (aux->race->getRaceId()!=1 )
    {
        cout << "...verifica_insertNode(raiz): O nó da raiz tem a corrida (="<<aux->race->getRaceId()<<") e' diferente do esperado (=1) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_insertNode(raiz): O nó da raiz tem a corrida (="<<aux->race->getRaceId()<<") (ok)" << endl;
    }

    /*Teste 2*/

    if (aux->left!=nullptr) {
     aux=aux->left;
    if (aux->race->getRaceId()!=26) {
        cout << "...verifica_insertNode(nó da esquerda da raiz ): O nó da esquerda da raiz tem a corrida (="<<aux->race->getRaceId()<<") e' diferente do esperado (=26) (ERRO)"<< endl ;
        er++;
        
    }    
    else 
        cout << "...verifica_insertNode(nó da esquerda da raiz): O nó da esquerda da raiz tem a corrida (="<<aux->race->getRaceId()<<") (ok)" << endl;
       
    } else { cout << "...verifica_insertNode(nó da esquerda da raiz): Não existe nó da esquerda da raiz (ERRO)"<< endl ;
        er++;}
} else  {
    cout << "...verifica_insertNode(raiz): A raiz não tem nenhum nó (ERRO)"<< endl ;
       er++;
}
    
  
    return er;
}

int verifica_driverVictoriesGP(RaceManagementTree &racManagerTree)
{
    int er = 0;
    vector<pair<string,int>>  vr;
    vr=racManagerTree.driverVictoriesGP(racManagerTree.getRoot(),4);
  
   
    int res=vr.size();
    if (res!=5)
    {
        cout << "...verifica_driverVictoriesGP( circuito Circuit de Barcelona-Catalunya):  Total de pilotos vitoriosos (="<<res<<") e' diferente do esperado (=5) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_driverVictoriesGP( circuito Circuit de Barcelona-Catalunya):  Total de pilotos vitoriosos (="<<res<<") (ok)" << endl;
    } 
    int k=1;
    string strtotal="";
    for (pair<string,int> &s:vr) {
  
            strtotal += to_string(k)+"-"+s.first+":"+to_string(s.second)+" ";
            k++;
    }
    

    string str="1-Kimi Räikkönen:2 2-Felipe Massa:1 3-Fernando Alonso:1 4-Jenson Button:1 5-Michael Schumacher:1";
if (!strtotal.empty()) strtotal.pop_back();
    if (strtotal!=str)
    {
        cout << "...verifica_driverVictoriesGP ( circuito Circuit de Barcelona-Catalunya):  Resultado (="<<strtotal<<") e' diferente do esperado (="<<str<<") (ERRO)"<< endl ;
        er++;
    }
     else 
        cout << "...verifica_driverVictoriesGP( circuito Circuit de Barcelona-Catalunya):  Resultado(="<<strtotal<<") (ok)" << endl;     
     
        
                      
      
    
    return er;
}


int verifica_bestPerformance(RaceManagementTree &racManagerTree)
{
    int er = 0;
    
    int g=0,p=0;
  string res=racManagerTree.bestPerformance(racManagerTree.getRoot(),2005,1,g,p);


    if (res!="Fernando Alonso")
    {
        cout << "...verifica_bestPerformance(1ª corridade 2005): Piloto (="<<res<<") e' diferente do esperado (=Fernando Alonso) (ERRO)"<< endl ;
           er++;
    }
    else
        
        cout << "...verifica_bestPerformance(1ª corridade 2005): Piloto (="<<res<<") (ok)" << endl;
    if (g!=13 || p!=3) {
        cout << "...verifica_bestPerformance(1ª corridade 2005): "<<res<<" partiu de "<<g<<"º e chegou em "<<p<<"º lugar e' diferente do esperado (=partir em 13º e chegar em 3º) (ERRO)"<< endl ;
           er++;
    }
    else
        
        cout << "...verifica_bestPerformance(1ª corridade 2005):"<<res<<" partiu de "<<g<<"º e chegou em "<<p<<"º lugar (ok)" << endl;
        
    
    
    return er;
}


int importDrivers (string filename, DriverManagement &manager) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open allDrivers.txt file." << endl;
        return -1;
    }
    int count=0;
    string line;
   
    Driver* driv;
    stringstream ss;
    int driveI;
    while (getline(file, line)) {
        
        string driId, cod, nam, dob,nat;
        
            
        ss.clear();
        ss << line; 
        driId.clear();
        
        getline(ss, driId, ';');
        
       
      
        driveI=stoi(driId);

       
        getline(ss, cod, ';');
        
        getline(ss, nam, ';');
        getline(ss, dob, ';');
        getline(ss, nat, ';');
        
     
     driv = new Driver(driveI, cod, nam, dob, nat);
       
       manager.driverInsert(driv);
        count++;
    }
   
    
    file.close();


    return count;

}


int importnumbers (string filename, DriverManagement &manager) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open numbers.csv file." << endl;
        return -1;
    }

    string line;
    stringstream ss;
    vector<Driver*> vmanager=manager.getVectorDrivers();
    getline(file, line);
    int count=0;
    while (getline(file, line)) {
        
        string driId, n;
        int driveI,num;
          
      
        ss.clear();
        ss << line; 
        getline(ss, driId, ';');
        driveI=stoi(driId);
        getline(ss, n, ';');
        num=stoi(n);
    
        
        for (size_t i=0;i<vmanager.size();i++){
            if (vmanager[i]->getDriverId()==driveI) {
                vmanager[i]->addNumber(num);
            }
        }
    count++;
    }
   
    
    file.close();

  
    return 0;
}

int importConstructors (string filename, ConstructorManagement &manager) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open allConstructors.txt file." << endl;
        return -1;
    }
    int count=0;
    string line;
   
    Constructor* constr;
    stringstream ss;
    int constrI;
    string constrId, nam, nat;
    getline(file, line);
    while (getline(file, line)) {
        
        
        
            
        ss.clear();
        ss << line; 
        
        
        getline(ss, constrId, ';');
        
      
      
        constrI=stoi(constrId);

       
        getline(ss, nam, ';');
        
      
        getline(ss, nat, ';');
           
     
     constr = new Constructor(constrI, nam, nat);
       
       manager.addConstrutor(constr);
        count++;
    }
   
    
    file.close();


    return count;

}


int importCircuits (string filename, CircuitManagement &manager) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open allCircuits.csv file." << endl;
        return -1;
    }
    int count=0;
    string line;
   
    Circuit* circ;
    stringstream ss;
    int circuitI,al;
    while (getline(file, line)) {
        
        string cird, nam, lat,coun,alt;
        
            
        ss.clear();
        ss << line; 
        cird.clear();
        
        getline(ss, cird, ';');
        
       
      
        circuitI=stoi(cird);
        
        getline(ss, nam, ';');
        getline(ss, lat, ';');
        getline(ss, coun, ';');
        getline(ss, alt, ';');
        al=stoi(alt);
     
        circ = new Circuit(circuitI, nam, alt, coun,al);
       
       manager.circuitInsert(circ);
        count++;
    }
   
    
    file.close();


    return count;

}


vector<Qualifying> importQualifying (string filename, DriverManagement &manager) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open qualifying.csv file." << endl;
        return {};
    }
    vector<Qualifying> vq;
    string line;
    stringstream ss;
    vector<Driver*> vmanager=manager.getVectorDrivers();
  
 
    int count=0;
    while (getline(file, line)) {
        
        string driId, n;
        int driveI;
        double num;
          
      
        ss.clear();
        ss << line; 
        getline(ss, driId, ';');
        driveI=stoi(driId);
        getline(ss, n, ';');
        num=stod(n);
    
        
        for (size_t i=0;i<vmanager.size();i++){
            if (vmanager[i]->getDriverId()==driveI) {
                vq.push_back({vmanager[i],num});
                break;
            }
        }
    count++;
    }
   
    
    file.close();

  
    return vq;
}


int importRaces (string filename, RaceManagement &manager, CircuitManagement &cirManager) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open allRaces.csv file." << endl;
        return -1;
    }
    int count=0;
    string line;
   
    Race* rac;
    stringstream ss;
    int raceI,coun,seas,circuitI;
    Circuit* cir=NULL;
    list<Circuit*> lc=cirManager.getListCircuits();
  
    while (getline(file, line)) {
        
        string race,cird, cou, sea,dat;
        
            
        ss.clear();
        ss << line; 
        race.clear();
        
        getline(ss, race, ';');
        raceI=stoi(race);
        
        getline(ss, sea, ';');
        seas=stoi(sea);
        getline(ss, cou, ';');
        coun=stoi(cou);
        getline(ss, cird, ';');
        circuitI=stoi(cird);
        getline(ss, dat, ';');
        cir=NULL;
         for (auto it=lc.begin();it!=lc.end();it++) {
            if ((*it)->getCircuitId()==circuitI) {
                cir=*it;
            }

         }
         if (cir!=NULL) {
        rac = new Race(raceI,seas,coun,cir, dat);
       
        manager.raceInsert(rac);
        count++;
         }
    }
   
    
    file.close();


    return count;

}


int main()
{

     int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
   
    DriverManagement driverManager;
    ConstructorManagement constrManager;
    CircuitManagement cirManager;
    RaceManagement racManager;
    RaceManagementTree racManagerTree;
    int a=importDrivers("alldrivers.csv",driverManager);
    cout <<"Importou: "<<a<<" drivers"<<endl;
    importnumbers("numbers.csv",driverManager);
    int b=importConstructors("allconstructors.csv",constrManager);
    cout <<"Importou: "<<b<<" constructors"<<endl;
    int c=importCircuits("allcircuits.csv",cirManager);
    cout <<"Importou: "<<c<<" cuircuits"<<endl;
    int d=importRaces("allraces.csv",racManager,cirManager);
    cout <<"Importou: "<<d<<" races"<<endl;
    int e=racManager.uploadFromFile("allresults.csv",driverManager, constrManager);
    cout <<"Importou: "<<e<<" resultados"<<endl<<endl;
   
 //   racManagerTree.inorder();





    error = verifica_moreTimesNumber(racManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_moreTimesNumber\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_moreTimesNumber passou\n\n" << endl;
    } 

    error = verifica_startingGrid(racManager,driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_startingGrid\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_startingGrid passou\n\n" << endl;
    }  

    error = verifica_insertNode(racManagerTree,racManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_insertNode\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_insertNode passou\n\n" << endl;
    } 

  
    error = verifica_driverVictoriesGP(racManagerTree);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_driverVictoriesGP\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_driverVictoriesGP passou\n\n" << endl;
    } 

 
  
    error = verifica_bestPerformance(racManagerTree);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_bestPerformance\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_bestPerformance passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}
