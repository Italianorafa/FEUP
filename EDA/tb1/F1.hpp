#include <vector>
#include <string>




using namespace std;

/* CLASSES */

class Driver; /** @brief Class to represent a Driver. */
class Constructor; /** @brief Class to represent all drivers. */
class DriverManagement; /** @brief Class to represent all drivers. */
class ConstructorManagement; /** @brief Class to represent all Constructor. */

/* STRUCTS */


/**/
struct DriCons {
    int begin;
    int end;
    Driver *driver;

    DriCons(int b,int e , Driver* dri): begin(b),end(e),driver(dri) {}

};

class Driver {
    private:
        /* ATTRIBUTES */
        int driverId; /** @brief driver id */
        string code; /** @brief 3-letter alphabet code of driver */
        string name; /** @brief Name */
        vector<int> numbers; /** @brief All the numbers the driver used */
        string dateOfBirth ; /** @brief Date of birth */
        string nationality; /** @brief Nationality*/

    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (parameterized) - Create an object of the class Driver.
         *  @param driverI driver Id.
         *  @param cod 3-letter alphabet code of driver.
         *  @param nam Name.
         *  @param numbe Vector with the numbers the driver used.
         *  @param dateOfBir Date of birth. 
         *  @param nationali Country.
         *  @note  Initialize each attribute with the corresponding argument.
         */
        Driver (int driverI, string cod, string nam, vector<int> numbe, string dateOfBir, string  nationali);
        Driver (int driverI, string cod, string nam, string dateOfBir, string  nationali);

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the driver Id.
         *  @return 'driverId' attribute.
         */
        int getDriverId() const;

        /** 
         *  @brief  Get the code of the driver.
         *  @return 'code' attribute.
         */
        string getCode() const;
        
          /** 
         *  @brief  Get the name of the driver.
         *  @return 'name' attribute.
         */
        string getName() const;


        /** 
         *  @brief  Get the number numbers the driver used.
         *  @return 'numbers' attribute.
         */
        vector<int> getNumbers() const;
        
        /** 
         *  @brief  Get the date of birth.
         *  @return 'dateOfBirth' attribute.
         */
        string getDateOfBirth() const;
        
        /** 
         *  @brief  Get the country.
         *  @return 'nationality' attribute.
         */
        string  getNationality() const;

         /* --- set Methods --- */
        /** 
         *  @brief  add a new number. The number must be from 1 to 199.
         *  @return 0 if 0 if inserted successfully, 1 if that number already existed and -1 if an error occurred..
         */
        int addNumber(int num);
        
        /* --- Other Methods --- */

        /** 
         *  @brief  Display the information of a Driver.
         *  @return void
         */
        void displayDriverInfo(ostream& os) const;


};

class Constructor {
    private:
        /* ATTRIBUTES */
        int constructorId; /** @brief Constructor Id. */
        string name; /** @brief Name of Constructor. */
        string nationality; /** @brief Country. */
        vector<DriCons*> Drivers; /** @brief Vector with all drivers who passed through the Constructor. */
       
    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (parameterized) - Create an object of the class Constructor.
         *  @param constructorId Constructor Id.
         *  @param name Name of the ConstructorId.
         *  @param country Country of the ConstructorId.
         *  @note  Initialize each attribute with the corresponding argument.
         */
        Constructor(int constructorId, string name, string country);

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the constructor's constructorId.
         *  @return 'ConstructorId' attribute.
         */
        int getConstructorId() const;

        /** 
         *  @brief  Get the user's name.
         *  @return 'name' attribute.
         */
        string getName() const;

        /** 
         *  @brief  Get the user's country.
         *  @return 'country' attribute.
         */
        string getCountry() const;

        /** 
         *  @brief  Get the all drivers who passed through the Constructor.
         *  @return 'Drivers' attribute.
         */
        vector<DriCons*> getDrivers();


        /* --- Other Methods --- */



        int deleteDriver(int driveId);

        /** 
         *  @brief  Add a new driver or a new year to a DriCons that already exists.
         *  @param  driverId drive Id.
         *  @param  year year.
         *  @return 0 if the new drivers or a new year is added successfully | 1 if the new drivers or the new year already exists |
         *  @return -1 if the parameteres are invalid or drivers not exist
         *  @note Formula 1 started in 1950 and there are no future years
         */
        int addDriver(int driveId, int year, DriverManagement &driveManager);

      
};

class DriverManagement {
    private:
        /* ATTRIBUTES */
        vector<Driver*> vectorDrivers; /** @brief Vector with all the Drivess. */
    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (default) - Create an object of the class DriverManagement.
         *  @note  Make sure the vector 'vectorDrivers' is empty.
         */
        DriverManagement();

        /** 
         *  @brief Desconstructor (default) - Delete all the  object of the vector 'vectorDrivers'.
         */
        ~DriverManagement();

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the vector with all the Drivers.
         *  @return 'vectorDrivers' attribute.
         */
        vector<Driver*> getVectorDrivers() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new driver.
         *  @param  driver New driver to be added.
         *  @return 0 if the driver is added successfully | -1 if the parameter is invalid | 1 if the driver already exists in the vector
         */
        int driverInsert(Driver* driver);

        /** 
         *  @brief  Remove a driver.
         *  @param  driverId Driver Id of the driver to be removed.
         *  @return 0 if the driver is removed successfully | -1 if the driver does not exist in the vector
         */
        int driverDelete(int driverId);
};

class ConstructorManagement {
    private:
        /* ATTRIBUTES */
        vector<Constructor*> vectorConstructores; /** @brief Vector with all Constructores. */

    public:
        /* METHODS */

        /** 
         *  @brief Constructor (default) - Create an object of the class ConstructorManagement.
         *  @note  Make sure the vector 'vectorConstructores' is empty.
         */
        ConstructorManagement();

          /** 
         *  @brief Desconstructor (default) - Delete all the  object of the vector 'vectorConstructores'.
         */
        ~ConstructorManagement();

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the vector with all the constructores.
         *  @return 'vectorConstructores' attribute.
         */
        vector<Constructor*> getVectorConstructores() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new constructorto the vector.
         *  @param  newUser Constructor to be added.
         * @return 0 if the constructor is added successfully | -1 if the parameter is invalid | 1 if the constructor already exists in the vector
         */
        int addConstrutor(Constructor* newConstructor);

        /** 
         *  @brief  Update the drivers in the constructors by reading a text file.
         *  @param  filename Filename of the text file containing the drivers in the constructors information.
         *  @param  manager Object with all the Drivers in the platform.
         *  @return 0 if successful | -1 if an error occurs
         *  @note   Each line of the file contains the required information in the following format: constructorId;driverId;year
         *  @note   Other functions implemented in this library can be used to implement this method.
         *  @note   Check:
         *  @note    -> driver exists  : NO  -ignore this line
         *  @note    -> constructor exists: NO  - ignore this line | YES - update the vetor
         */ 
        int updateConstructorDrivers(string filename, DriverManagement& manager);


        /** 
         *  @brief  List with the name of the drivers and the Construtors from a given year.
         *  @param  year  year.
         *  @param  vConstr  Parameter to pass the list of Construtors ordered in ascending order.
         *  @return vector with the name of the drivers ordered in ascending order
         *  @note Formula 1 started in 1950 and there are no future years
         */ 
        vector<string> DriversAndConstructorsOfOneYear(int year,vector<string> &vConstr);
};
