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
    // 5 properties:
    //     1) number of strings (int)
    int numOfStrings = 4;
    //     2) type of pickup (std::string)
    std::string pickupType = "humbucker";
    //     3) number of frets (int)
    int numOfFrets = 24;
    //     4) volume output (float)
    float volumeOutput = 0.75f;
    //     5) number of tone controls (int)
    int numOfToneControls = 2;

    // 3 things it can do:
    //     1) play a note
    void playNote(int noteNumber);
    //     2) modify tone
    void modifyTone(int toneNumber);
    //     3) change volume
    float changeVolume(float volumeAdjustment); // returns new volume
};

/*
Thing 2) video game character
*/
struct VideoGameCharacter 
{
    // 5 properties:
    //     1) number of lives (int)
    int numOfLives = 3;
    //     2) current level (int)
    int currentLevel = 5;
    //     3) armor level (float)
    float armorLevel = 50.75f;
    //     4) experience bar (double)
    double experienceBar = 104300;
    //     5) amount of gold owned (double)
    double goldOwned = 538.53;

    struct EquippedWeapon 
    {
        // 5 properties:
        float minDamage = 5.0f;
        float maxDamage = 7.5f;
        std::string weaponType = "one-handed sword";
        int addedStrenghtAttribute = 10;
        float equippedWeight = 13.3f;

        // 3 functions:
        float calculateDamage(float minDamage, float maxDamage, int strengthModifier);
        bool isEquippable(float weight, bool playerHasSpace);
        float durability(int numOfAttacksMade);
    };

    // 3 things it can do:
    //     1) cast spell
    void castSpell(std::string spellName);
    //     2) select a skill
    void selectSkill(std::string skillName);
    //     3) attack with weapon
    float attackWithWeapon(EquippedWeapon currentWeapon); 

    EquippedWeapon currentWeapon;
};
/*
Thing 3) coffee shop
*/
struct CoffeeShop 
{
    // 5 properties:
    //     1) number of employees (int)
    int numOfEmployees = 10;
    //     2) number of coffee machines (int)
    int numOfCoffeeMachines = 3;
    //     3) number of cups sold per day (int)
    int numOfCupsSoldPerDay = 100;
    //     4) price of coffee (float)
    float priceOfCoffee = 6.75f;
    //     5) types of coffee options available (std::string)
    std::string typesOfCoffeeOptions = "latte";

    // 3 things it can do:
    //     1) make coffee
    int makeCoffee(std::string coffeeType); // returns a number of coffees
    //     2) sell coffee
    float sellCoffee(int numOfCups); // returns amount charged
    //     3) open and close shop
    bool openAndCloseShop(bool isOpen); // returns true if shop is open
};
/*
Thing 4) barbecue grill
*/
struct BarbecueGrill 
{
    // 5 properties:
    //     1) number of burners (int)
    int numOfBurners = 4;
    //     2) current interior temperature (float)
    float currentTempInFarenheit = 323.5f;
    //     3) fuel type (std::string)
    std::string fuelType = "propane";
    //     4) weight (float)
    float weight = 405.15f;
    //     5) material it's made of (std::string)
    std::string material = "stainless steel";

    // 3 things it can do:
    //     1) cook food
    void cookFood(std::string foodName);
    //     2) ignite burner
    bool igniteBurner(int burnerNumber);
    //     3) preheat
    float preheat(float temperature); // returns new temperature
};
/*
Thing 5) Engine
*/
struct PlaneEngine 
{
    // 5 properties:
    //     1) velocity (float)
    float velocity = 250.75f;
    //     2) acceleration (float)
    float acceleration = 5.75f;
    //     3) power (float)
    float horsePower = 30000.24f;
    //     4) fuel type (std::string)
    std::string fuelType = "diesel";
    //     5) engine type (std::string)
    std::string engineType = "turbojet";

    // 3 things it can do:
    //     1) accelerate 
    float accelerate(float acceleration);
    //     2) ignite
    bool ignite();
    //     3) activate turbo
    bool activateTurbo();
};
/*
Thing 6) Wings
*/
struct PlaneWings
{
    // 5 properties:
    //     1) wing loading (float)
    float wingLoadingInKG = 730.2f;
    //     2) lift to drag ratio (float)
    float liftToDragRatio = 17.0f;
    //     3) type/shape of wing (std::string)
    std::string wingType = "low swept";
    //     4) altitude (float))
    float altitude = 30000.0f;
    //     5) length (float)
    float wingSpan = 68.4f;

    // 3 things it can do:
    //     1) engage flaps
    bool engageFlaps();
    //     2) increase altitude
    float adjustAltitude(float altitudeAdjustment);
    //     3) adjust pitch, yaw, and roll
    void adjustPitchYawRoll(float newPitch, float newYaw, float newRoll);
};
/*
Thing 7) Cockpit
*/
struct PlaneCockpit
{
    // 5 properties:
    //     1) number of seats (int)
    int numOfSeats = 2;
    //     2) number of pilots (int)
    int numOfPilots = 2;
    //     3) fuel tank meters (float)
    float fuelTankMeter = 0.65f;
    //     4) spedometer (float)
    float currentSpeedInKMPerHour = 32.0f;
    //     5) odometer (float)
    float totalDistanceTraveledInKM = 12500.f;

    // 3 things it can do:
    //     1) signal crew for takeoff
    void signalCrewForTakeoff();
    //     2) engage/disengage landing gear
    bool engageLandingGear();
    //     3) adjust throttle
    float adjustThrottle(float throttleAdjustment);
};
/*
Thing 8) Seating Area
*/
struct PlaneCabin // renamed Seating Area to Cabin because it's a more accurate name
{
    // 5 properties:
    //     1) number of seats (int)
    int numOfSeats = 400;
    //     2) number of passengers (int)
    int numOfPassengers = 200;
    //     3) fasten seatbelt sign (bool)
    bool fastenSeatbeltSign = true;
    //     4) overhead storage bin capacity (float)
    float overheadStorageBinCapacityInCubicMeters = 3500.2f; 
    //     5) seat numbers (std::string)
    std::string seatNumber = "22C";

    struct FirstClassSection 
    {
        // 5 properties:
        int numOfFirstClassSeats = 16;
        float priceOfFirstClassSeat = 100.0f;
        std::string firstClassFoodOption = "steak and lobster";
        std::string firstClassDrinkOption = "champagne";
        float priceOfFirstClassFood = 55.99f;

        // 3 functions:
        bool engagePrivacyScreen(bool isPrivacyScreenEngaged);
        float purchaseFirstClassSeat(int numOfFirstClassSeats, float priceOfFirstClassSeat);
        bool isFirstClassSectionFull(int numOfFirstClassSeats);
    };

    // 3 things it can do:
    //     1) assign seats to passengers
    void assignSeatsToPassengers(std::string passengerName, FirstClassSection firstClassSection);
    //     2) store luggage
    float storeLuggage(float luggageVolume);
    //     3) turn on/off seatbelt sign
    bool turnOnSeatbeltSign();

    FirstClassSection firstClassSection;
};
/*
Thing 9) Storage
*/
struct PlaneStorage
{
    // 5 properties:
    //     1) max weight allowed (float)
    float storageCapacityInTonnes = 128.5f;
    //     2) width of storage area (float)
    float storageAreaWidthInMeters = 5.9f;
    //     3) length of storage area (float)
    float storageAreaLengthInMeters = 70.7f;
    //     4) height of storage area (float)
    float storageAreaHeightInMeters = 19.4f;
    //     5) number of stored luggage (int)
    int numOfStoredLuggage = 332;

    // 3 things it can do:
    //     1) fill storage space with luggage
    float fillStorage(float luggageVolume);
    //     2) empty storage space
    float emptyStorage(float luggageVolume);
    //     3) check if storage is full
    bool checkStorageStatus(float storageCapacity, int numOfStoredLuggage);
};
/*
Thing 10) airplane
*/
struct Airplane
{
    // 5 properties:
    //     1) engine
    PlaneEngine jetEngine;
    //     2) wings
    PlaneWings wings;
    //     3) cockpit
    PlaneCockpit cockpit;
    //     4) storage
    PlaneStorage storage;
    //     5) cabin
    PlaneCabin cabin;
    // 3 things it can do:
    //     1) accelerate
    float accelerate(PlaneEngine engine);
    //     2) liftoff
    bool liftoff();
    //     3) adjust altitude
    float adjustAltitude(float altitudeAdjustment);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
