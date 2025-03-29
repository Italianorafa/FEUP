#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "F1.hpp"

using namespace std;


int verifica_numberRacePerSeason(RaceManagement &manager)
{
    int er = 0;
    int res=manager.numberRacePerSeason(18);
   
    if (res!=3)
    {
        cout << "...verifica_numberRacePerSeason ( 18 races ): Total de épocas, retorno(="<<res<<") e' diferente do esperado (=3) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_numberRacePerSeason ( 18 races ):  Total de épocas, retorno =3 (ok)" << endl;
    }
        res=manager.numberRacePerSeason(2);
    if (res!=0)
    {
        cout << "...verifica_numberRacePerSeason ( 2 races ): Total de épocas, retorno(="<<res<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_numberRacePerSeason ( 2 races ):  Total de épocas, retorno =0 (ok)" << endl;
    

   
    return er;
}



int verifica_seasonGrandPrix(RaceManagement &manager)
{
    int er = 0;
  
    stringstream ss;
    string str="",strtotal="",str1;
    queue<string> que=manager.seasonGrandPrix(2004);
    size_t res=que.size();
  
 
    if (!strtotal.empty()) { strtotal.pop_back(); strtotal.pop_back();}

    /*Teste 1*/
   if (res!=18)
    {
        cout << "...verifica_seasonGrandPrix(época 2004): Numero de Grande prémios (="<<res<<") e' diferente do esperado (=18) (ERRO)"<< endl;
           er++;
    }
    else
        cout << "...verifica_seasonGrandPrix(época 2004): Numero de Grande prémios (=18) (ok) "<< endl;

    /*Teste 2*/
    str="Albert Park Grand Prix Circuit Sepang International Circuit Bahrain International Circuit Autodromo Enzo e Dino Ferrari Circuit de Barcelona-Catalunya Circuit de Monaco Nürburgring Circuit Gilles Villeneuve Indianapolis Motor Speedway Circuit de Nevers Magny-Cours Silverstone Circuit Hockenheimring Hungaroring Circuit de Spa-Francorchamps Autodromo Nazionale di Monza Shanghai International Circuit Suzuka Circuit Autódromo José Carlos Pace";
    while(!que.empty())
    {
            strtotal += que.front()+" ";
            que.pop();
    }
    if (!strtotal.empty()) strtotal.pop_back();
   if (str!=strtotal)
   {
       cout << "...verifica_seasonGrandPrix(época 2020): Grande prémios (="<<strtotal<<") e' diferente do esperado (="<<str<<") (ERRO)"<< endl;
          er++;
   }
   else
       cout << "...verifica_seasonGrandPrix(época 2020): Grande prémios (="<<strtotal<<") (ok) "<< endl<< strtotal<<endl;


    return er;
}
   



int verifica_driverStatus(RaceManagement &manager)
{
    int er = 0;
    int n=0;
    string res=manager.driverStatus("Engine",n);
 

    if (res!="Kimi Räikkönen" )
    {
        cout << "...verifica_driverStatus: Quem teve mais problemas com o motor  (piloto ="<<res<<") e' diferente do esperado (=Kimi Räikkönen) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_driverStatus: Quem teve mais problemas com o motor  (piloto ="<<res<<") (ok)" << endl;
    }
    /*Teste 2*/
    if (n!=7) {
            cout << "...verifica_addDriver: O numero de problemas de motor (="<<n<<") e' diferente do esperado (=6) do "<<res<<" (ERRO)"<< endl ;
            er++;
            
        }    
        else 
            cout << "...verifica_driverStatus:  O numero de problemas de motor (="<<n<<") do "<<res<<" é o esperado (ok)" << endl;
           
  
    return er;
}

int verifica_uploadFromFile(RaceManagement &manager,  DriverManagement &driverManager, ConstructorManagement &constrManager)
{
    int er = 0;
    int res=manager.uploadFromFile("allresults.csv",driverManager, constrManager);
   
    if (res!=2213)
    {
        cout << "...verifica_uploadFromFile:  retorno(="<<res<<") e' diferente do esperado (=2213) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_uploadFromFile:  retorno (="<<res<<") (ok)" << endl;
     

        list<Race*> manag=manager.getListRaces();
        auto it=manag.begin();
             for (int  i=0;i<10;i++) {
                it++;
             }
             string countr=(*it)->getCircuit()->getCountry();
             int seaso=(*it)->getSeason();
             size_t tam=(*it)->getListRaceResults().size();
             if (tam!=20)
             {
                 cout << "...verifica_uploadFromFile ( grande premio de "<<countr<<" de "<<seaso<<"):  Numero de pilotos que participaram na corrida (="<<tam<<") e' diferente do esperado (=20) (ERRO)"<< endl ;
                    er++;
             }
             else 
                 cout << "...verifica_uploadFromFile ( grande premio de "<<countr<<" de "<<seaso<<"):  Numero de pilotos que participaram na corrida (="<<tam<<") (ok)" << endl;     
     
             string primeiro="";
             list<DriResult*> ld=(*it)->getListRaceResults();
             for (auto it1=ld.begin();it1!=ld.end();it1++){
                if ((*it1)->position==1) {
                    primeiro=(*it1)->drive->getName();
                }
             }
             if (primeiro!="Rubens Barrichello") {
                cout << "...verifica_uploadFromFile ( grande premio de "<<countr<<" de "<<seaso<<"):  1º classificado (="<<primeiro<<") e' diferente do esperado (=Rubens Barrichello) (ERRO)"<< endl ;
                er++;
         }
         else 
             cout << "...verifica_uploadFromFile ( grande premio de "<<countr<<" de "<<seaso<<"):   1º classificado (="<<primeiro<<") (ok)" << endl;     
 
                      
      
    }
    return er;
}


int verifica_scoreCareer(RaceManagement &manager, DriverManagement &driverManager)
{
    int er = 0;
    int n=0;
    int  res=manager.scoreCareer(8,driverManager,n);

    if (res!=455)
    {
        cout << "...verifica_scoreCareer(Kimi Räikkönen): Pontuação total da carreira (="<<res<<") e' diferente do esperado (=455) (ERRO)"<< endl ;
           er++;
    }
    else
        
        cout << "...verifica_scoreCareer(Kimi Räikkönen): Pontuação total da carreira (="<<res<<") (ok)" << endl;
    if (n!=14) {
        cout << "...verifica_scoreCareer(Kimi Räikkönen): Pole position (="<<n<<") e' diferente do esperado (=14) (ERRO)"<< endl ;
           er++;
    }
    else
        
        cout << "...verifica_scoreCareer(Kimi Räikkönen): Pole position (="<<n<<") (ok)" << endl;
        
    
    
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
    int a=importDrivers("alldrivers.csv",driverManager);
    cout <<"Importou: "<<a<<" drivers"<<endl;
    importnumbers("numbers.csv",driverManager);
    int b=importConstructors("allconstructors.csv",constrManager);
    cout <<"Importou: "<<b<<" constructors"<<endl;
    int c=importCircuits("allcircuits.csv",cirManager);
    cout <<"Importou: "<<c<<" cuircuits"<<endl;
    int d=importRaces("allraces.csv",racManager,cirManager);
    cout <<"Importou: "<<d<<" races"<<endl<<endl;
    

   

    error = verifica_numberRacePerSeason(racManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_numberRacePerSeason\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_numberRacePerSeason passou\n\n" << endl;
    } 

    error = verifica_seasonGrandPrix(racManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_seasonGrandPrix\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_seasonGrandPrix passou\n\n" << endl;
    }  

    error = verifica_uploadFromFile(racManager, driverManager, constrManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_uploadFromFile\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_uploadFromFile passou\n\n" << endl;
    } 

    
    error = verifica_driverStatus(racManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_driverStatus\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_driverStatus passou\n\n" << endl;
    } 

 
   
    error = verifica_scoreCareer(racManager, driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_scoreCareer\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_scoreCareer passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}
