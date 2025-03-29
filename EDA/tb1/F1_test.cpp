#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "F1.hpp"

using namespace std;


int verifica_addNumber(DriverManagement &manager)
{
    int er = 0;
    Driver *driv=manager.getVectorDrivers()[829];
   
    vector<int> v=driv->getNumbers();
    int res=v.size();
    if (res!=2)
    {
        cout << "...verifica_addNumber: Total dos numeros do carro do Max Verstappen, retorno(="<<res<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_addNumber:  Total dos numeros do carro do Max Verstappen, retorno =2 (ok)" << endl;
    
    bool ok=true;
    int n1=33;
    int n2=1;
    string str;
 
        for(auto i=0;i<v.size();i++)
        {
            str+=v[i]+" ";
            if ( (v[i]!=n1) && (v[i]!=n2) ) 
            {
                ok=false;
            }

        }
        str.pop_back();
    if (!ok)
    {
        cout << "...verifica_addNumber: Os numeros do carro do Max Verstappen, retorno(="<<str<<") e' diferente do esperado (=33 1) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_addNumber: Os numeros do carro do Max Verstappen, retorno =33 1 (ok)" << endl;
    }

   
    return er;
}



int verifica_displayDriverInfo(DriverManagement &manager)
{
    int er = 0;
  
    stringstream ss;
    string str,strtotal="",str1;
    str1="Displaying driver info:\n-----DriverId: 1\n-----Code: HAM\n-----Name: Lewis Hamilton\n-----used numbers: 22 2 1 3 4 10 44\n-----Date of birth: 1/7/1985\n-----Country: British";
    manager.getVectorDrivers()[0]->displayDriverInfo(ss);
    while(getline(ss,str))
    {
            strtotal += str+"\n";
    }
 
    if (!strtotal.empty()) { strtotal.pop_back(); strtotal.pop_back();}

    /*Teste 1*/
   if (strtotal!=str1)
    {
        cout << "...verifica_displayDriverInfo: Informação do Lewis Hamilton está incorreta - " << endl<< strtotal <<endl << "Devia aparecer:" << endl << str1 << endl;
           er++;
    }
    else
        cout << "...verifica_displayDriverInfo: Informação do Lewis Hamilton  está correta (ok) "<< endl<< strtotal<<endl;

    return er;
}
   



int verifica_addDriver(ConstructorManagement &constrManager,DriverManagement &driverManager)
{
    int er = 0;
    string resD="";
    int resYb=0;
    int resYe=0;
    int res=constrManager.getVectorConstructores()[5]->addDriver(13,2008,driverManager);
    int resS=constrManager.getVectorConstructores()[5]->getDrivers().size();
    if (resS==1) {
    resD=constrManager.getVectorConstructores()[5]->getDrivers()[0]->driver->getName();
    resYb=constrManager.getVectorConstructores()[5]->getDrivers()[0]->begin;
    resYe=constrManager.getVectorConstructores()[5]->getDrivers()[0]->end; }
    if (res!=0 )
    {
        cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2008): O retorno da função(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2008): Retorno =0 (ok)" << endl;
        if (resS!=1) {
            cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2008): O numero de pilotos na Ferrari(="<<resS<<") e' diferente do esperado (=1) (ERRO)"<< endl ;
            er++;
            
        }    
        else {
            cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2008):  O numero de pilotos na Ferrari=1 (ok)" << endl;
            if (resD!="Felipe Massa" && resYb!=2008 && resYe!=2008) {
                cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2008): Ou o nome do piloto(="<<resD<<") e' diferente do esperado (=Felipe Massa), ou o ano de inicio(="<<resYb<<") é diferente do esperado (=2008), ou o ano de fim(="<<resYb<<") é diferente do esperado (=2008) (ERRO)"<< endl ;
                er++;
                
            }    else 
            cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2008):  Inseriu com sucesso" << endl;
             
        }
           
    }    

    /*Teste 2*/

    res=constrManager.getVectorConstructores()[5]->addDriver(13,2009,driverManager);
    resS=constrManager.getVectorConstructores()[5]->getDrivers().size();
    if (resS==1) {
    resD=constrManager.getVectorConstructores()[5]->getDrivers()[0]->driver->getName();
    resYb=constrManager.getVectorConstructores()[5]->getDrivers()[0]->begin;
    resYe=constrManager.getVectorConstructores()[5]->getDrivers()[0]->end; }
    if (res!=0 )
    {
        cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2009): O retorno da função(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2009): Retorno =0 (ok)" << endl;
        if (resS!=1) {
            cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2009): O numero de pilotos na Ferrari(="<<resS<<") e' diferente do esperado (=1) (ERRO)"<< endl ;
            er++;
            
        }    
        else {
            cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2009): O numero de pilotos na Ferrari=1 (ok)" << endl;
            if (resD!="Felipe Massa" && resYb!=2008 && resYe!=2009) {
                cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2009): Ou o nome do piloto(="<<resD<<") e' diferente do esperado (=Felipe Massa), ou o ano de inicio(="<<resYb<<") é diferente do esperado (=2008), ou o ano de fim(="<<resYb<<") é diferente do esperado (=2009) (ERRO)"<< endl ;
                er++;
                
            }    else 
            cout << "...verifica_addDriver(Inserir Felipe Massa na Ferrari em 2009): Inseriu com sucesso" << endl;
             
        }
           
    }    
  
     /*Teste 3*/

     res=constrManager.getVectorConstructores()[5]->addDriver(4,2009,driverManager);
     resS=constrManager.getVectorConstructores()[5]->getDrivers().size();
     if (resS==2) {
     resD=constrManager.getVectorConstructores()[5]->getDrivers()[0]->driver->getName();
     resYb=constrManager.getVectorConstructores()[5]->getDrivers()[0]->begin;
     resYe=constrManager.getVectorConstructores()[5]->getDrivers()[0]->end; }
     if (res!=0 )
     {
         cout << "...verifica_addDriver(Inserir Fernando Alonso na Ferrari em 2009): O retorno da função(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
            er++;
     }
     else {
         cout << "...verifica_addDriver(Inserir Fernando Alonso na Ferrari em 2009): Retorno =0 (ok)" << endl;
         if (resS!=2) {
             cout << "...verifica_addDriver(Inserir Fernando Alonso na Ferrari em 2009): O numero de pilotos na Ferrari(="<<resS<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
             er++;
             
         }    
         else {
             cout << "...verifica_addDriver(Inserir Fernando Alonso na Ferrari em 2009): O numero de pilotos na Ferrari=2 (ok)" << endl;
             if (resD!="Felipe Massa" && resYb!=2009 && resYe!=2009) {
                 cout << "...verifica_addDriver(Inserir Fernando Alonso na Ferrari em 2009): Ou o nome do piloto(="<<resD<<") e' diferente do esperado (=Fernando Alonso), ou o ano de inicio(="<<resYb<<") é diferente do esperado (=2009), ou o ano de fim(="<<resYb<<") é diferente do esperado (=2009) (ERRO)"<< endl ;
                 er++;
                 
             }    else 
             cout << "...verifica_addDriver(Inserir Fernando Alonso na Ferrari em 2009): Inseriu com sucesso" << endl;

         }
            
     }   

    return er;
}

int verifica_updateConstructorDrivers(ConstructorManagement &constrManager, DriverManagement &driverManager)
{
    int er = 0;
    int res=constrManager.updateConstructorDrivers("allConstruDrivers.csv",driverManager);
   
    if (res!=0)
    {
        cout << "...verifica_updateConstructorDrivers:  retorno(="<<res<<") e' diferente do esperado (=-1) (ERRO)"<< endl ;
           er++;
    }
    else {
        cout << "...verifica_updateConstructorDrivers:  retorno =0 (ok)" << endl;
        int tam=constrManager.getVectorConstructores()[45]->getDrivers().size();
        if (tam!=2) {
            cout << "...verifica_updateConstructorDrivers(Construtor Life): O numero de pilotos na Life(="<<tam<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
            er++;
            
        }    
        else {
             cout << "...verifica_updateConstructorDrivers(Construtor Life): O numero de pilotos na Life=2 (ok)" << endl;
             string redD1=constrManager.getVectorConstructores()[45]->getDrivers()[0]->driver->getName();
             int redYb1=constrManager.getVectorConstructores()[45]->getDrivers()[0]->begin;
             int redYe1=constrManager.getVectorConstructores()[45]->getDrivers()[0]->end;
             string redD2=constrManager.getVectorConstructores()[45]->getDrivers()[1]->driver->getName();
             int redYb2=constrManager.getVectorConstructores()[45]->getDrivers()[1]->begin;
             int redYe2=constrManager.getVectorConstructores()[45]->getDrivers()[1]->end;
            bool okYear=false;
            if(redYb1==1990 && redYe1==1990 && redYb2==1990 &&redYe2==1990) okYear=true;
            bool okName=false;
            if((redD1=="Gary Brabham" or redD1=="Bruno Giacomelli")  && (redD2=="Gary Brabham" or redD2=="Bruno Giacomelli") ) okName=true;
             if (!okYear && !okName) {
                cout << "...verifica_updateConstructorDrivers(Construtor Life(Gary Brabham and Bruno Giacomelli in 1990)): Ou os nomes dos pilotos(="<<redD1<<" and "<<redD2<<") sao diferente do esperado (=Gary Brabham and Bruno Giacomelli), ou o ano de inicio(="<<redYb1<<" and "<<redYb2<<")  é diferente do esperado (=2009), ou o ano de fim(="<<redYe1<<" and "<<redYe2<<") é diferente do esperado (=1900) (ERRO)"<< endl ;
                er++;
                
            }    else 
            cout << "...verifica_addDriver(Construtor Life(Gary Brabham and Bruno Giacomelli in 1990)): Inseriu com sucesso" << endl;
             
        }
      
    }
    return er;
}


int verifica_DriversAndConstructorsOfOneYear(ConstructorManagement &constrManager, DriverManagement &driverManager)
{
    int er = 0;
    vector<string> vC;
    vector<string>  v=constrManager.DriversAndConstructorsOfOneYear(2018,vC);
    int res=v.size();
    if (res!=20)
    {
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Numero de pilotos(="<<res<<") e' diferente do esperado (=20) (ERRO)"<< endl ;
           er++;
    }
    else
        {
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Numero de pilotos=20 (ok)" << endl;
        string names=v[0];
        for (size_t i=1;i<v.size();i++) {
            names=names+"-"+v[i];
        }
        string na="Brendon Hartley-Carlos Sainz-Charles Leclerc-Daniel Ricciardo-Esteban Ocon-Fernando Alonso-Kevin Magnussen-Kimi Räikkönen-Lance Stroll-Lewis Hamilton-Marcus Ericsson-Max Verstappen-Nico Hülkenberg-Pierre Gasly-Romain Grosjean-Sebastian Vettel-Sergey Sirotkin-Sergio Pérez-Stoffel Vandoorne-Valtteri Bottas";
    if (na!=names) {
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Nomes dos pilotos(="<<names<<") e' diferente do esperado (="<<na<<") (ERRO)"<< endl ;
           er++;
    }
    else
        
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Nomes dos pilotos(="<<names<<") (ok)" << endl;
        
    }
    res=vC.size();
    if (res!=10)
    {
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Numero de Construtores(="<<res<<") e' diferente do esperado (=10) (ERRO)"<< endl ;
           er++;
    }
    else
        {
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Numero de Construtores=10 (ok)" << endl;
       
        string names=vC[0];
        for (size_t i=1;i<vC.size();i++) {
            names=names+"-"+vC[i];
        }
        
        string na="Ferrari-Force India-Haas F1 Team-McLaren-Mercedes-Red Bull-Renault-Sauber-Toro Rosso-Williams";
    if (na!=names) {
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Nomes dos Construtores(="<<names<<") e' diferente do esperado (="<<na<<") (ERRO)"<< endl ;
           er++;
    }
    else
        
        cout << "...verifica_DriversAndConstructorsOfOneYear(2018): Nomes dos Construtores(="<<names<<") (ok)" << endl;
        
    }
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

int main()
{

     int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
   
    DriverManagement driverManager;
    ConstructorManagement constrManager;
    int a=importDrivers("alldrivers.csv",driverManager);
    cout <<"Importou: "<<a<<" drivers"<<endl;
    importnumbers("numbers.csv",driverManager);
    int b=importConstructors("allconstructors.csv",constrManager);
    cout <<"Importou: "<<b<<" constructors"<<endl;
    

    error = verifica_addNumber(driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_addNumber\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_addNumber passou\n\n" << endl;
    } 

    error = verifica_displayDriverInfo(driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_displayDriverInfo\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_displayDriverInfo passou\n\n" << endl;
    }  


    error = verifica_addDriver(constrManager,driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_addDriver\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_addDriver passou\n\n" << endl;
    } 

    error = verifica_updateConstructorDrivers(constrManager, driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_updateConstructorDrivers\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_updateConstructorDrivers passou\n\n" << endl;
    } 

    
   
    error = verifica_DriversAndConstructorsOfOneYear(constrManager, driverManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_DriversAndConstructorsOfOneYear\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_DriversAndConstructorsOfOneYear passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}
