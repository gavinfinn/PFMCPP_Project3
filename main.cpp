 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person 
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int stepSize();
        void stepForward();
    };

    Foot leftFoot;
    Foot rightFoot;
    
    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward() {}
int Person::Foot::stepSize() { return 2; }

void Person::run(int howFast, bool startWithLeftFoot) 
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
Thing 1) bass guitar
*/
struct BassGuitar 
{
    int numOfStrings = 4;
    std::string pickupType = "humbucker";
    int numOfFrets = 24;
    float volumeOutput = 0.75f;
    int numOfToneControls = 2;

    void playNote(int noteNumber);
    void modifyTone(int toneNumber);
    float changeVolume(float volumeAdjustment);
};

/*
Thing 2) video game character
*/
struct VideoGameCharacter 
{
    int numOfLives = 3;
    int currentLevel = 5;
    float armorLevel = 50.75f;
    double experienceBar = 104300;
    double goldOwned = 538.53;

    struct EquippedWeapon 
    {
        float minDamage = 5.0f;
        float maxDamage = 7.5f;
        std::string weaponType = "one-handed sword";
        int addedStrenghtAttribute = 10;
        float equippedWeight = 13.3f;

        float calculateDamage(float minDamage, float maxDamage, int strengthModifier);
        bool isEquippable(float weight, bool playerHasSpace);
        float durability(int numOfAttacksMade);
    };

    void castSpell(std::string spellName);
    void selectSkill(std::string skillName);
    float attackWithWeapon(EquippedWeapon currentWeapon); 

    EquippedWeapon currentWeapon;
};
/*
Thing 3) coffee shop
*/
struct CoffeeShop 
{
    int numOfEmployees = 10;
    int numOfCoffeeMachines = 3;
    int numOfCupsSoldPerDay = 100;
    float priceOfCoffee = 6.75f;
    std::string typesOfCoffeeOptions = "latte";

    int makeCoffee(std::string coffeeType);
    float sellCoffee(int numOfCups); 
    bool openAndCloseShop(bool isOpen);
};
/*
Thing 4) barbecue grill
*/
struct BarbecueGrill 
{
    int numOfBurners = 4;
    float currentTempInFarenheit = 323.5f;
    std::string fuelType = "propane";
    float weight = 405.15f;
    std::string material = "stainless steel";

    void cookFood(std::string foodName);
    bool igniteBurner(int burnerNumber);
    float preheat(float temperature); 
};
/*
Thing 5) Engine
*/
struct Engine 
{
    float velocity = 250.75f;
    float acceleration = 5.75f;
    float horsePower = 30000.24f;
    std::string fuelType = "diesel";
    std::string engineType = "turbojet";

    float accelerate(float acceleration);
    bool ignite();
    bool activateTurbo();
};
/*
Thing 6) Wings
*/
struct Wings
{
    float wingLoadingInKG = 730.2f;
    float liftToDragRatio = 17.0f;
    std::string wingType = "low swept";
    float altitude = 30000.0f;
    float wingSpan = 68.4f;

    bool engageFlaps();
    float adjustAltitude(float altitudeAdjustment);
    void adjustPitchYawRoll(float newPitch, float newYaw, float newRoll);
};
/*
Thing 7) Cockpit
*/
struct Cockpit
{
    int numOfSeats = 2;
    int numOfPilots = 2;
    float fuelTankMeter = 0.65f;
    float currentSpeedInKMPerHour = 32.0f;
    float totalDistanceTraveledInKM = 12500.f;

    void signalCrewForTakeoff();
    bool engageLandingGear();
    float adjustThrottle(float throttleAdjustment);
};
/*
Thing 8) Seating Area
*/
struct Cabin 
{
    int numOfSeats = 400;
    int numOfPassengers = 200;
    bool fastenSeatbeltSign = true;
    float overheadStorageBinCapacityInCubicMeters = 3500.2f; 
    std::string seatNumber = "22C";

    struct FirstClassSection 
    {
        int numOfFirstClassSeats = 16;
        float priceOfFirstClassSeat = 100.0f;
        std::string firstClassFoodOption = "steak and lobster";
        std::string firstClassDrinkOption = "champagne";
        float priceOfFirstClassFood = 55.99f;

        bool engagePrivacyScreen(bool isPrivacyScreenEngaged);
        float purchaseFirstClassSeat(int numOfFirstClassSeats, float priceOfFirstClassSeat);
        bool isFirstClassSectionFull(int numOfFirstClassSeats);
    };

    void assignSeatsToPassengers(std::string passengerName, FirstClassSection firstClassSection);
    float storeLuggage(float luggageVolume);
    bool turnOnSeatbeltSign();

    FirstClassSection firstClassSection;
};
/*
Thing 9) Storage
*/
struct Storage
{
    float storageCapacityInTonnes = 128.5f;
    float storageAreaWidthInMeters = 5.9f;
    float storageAreaLengthInMeters = 70.7f;
    float storageAreaHeightInMeters = 19.4f;
    int numOfStoredLuggage = 332;

    float fillStorage(float luggageVolume);
    float emptyStorage(float luggageVolume);
    bool checkStorageStatus(float storageCapacity, int numOfStoredLuggage);
};
/*
Thing 10) airplane
*/
struct Airplane
{
    Engine jetEngine;
    Wings wings;
    Cockpit cockpit;
    Storage storage;
    Cabin cabin;

    float accelerate(Engine engine);
    bool liftoff();
    float adjustAltitude(float altitudeAdjustment);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
