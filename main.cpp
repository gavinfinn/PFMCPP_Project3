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
    void tune();
    float changeVolume(float volumeAdjustment);
};

void BassGuitar::playNote(int noteNumber)
{
    std::cout << "Playing note " << noteNumber << " on the bass guitar." << std::endl;
}

void BassGuitar::tune() {}

float BassGuitar::changeVolume(float volumeAdjustment) 
{
    return volumeOutput += volumeAdjustment;
}

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
        float addedStrengthAttribute = 10;
        float equippedWeight = 13.3f;

        float calculateDamage(EquippedWeapon weapon);
        bool isEquippable(float weight, bool playerHasSpace);
        float durability(int numOfAttacksMade);
    };

    void castSpell(std::string spellName);
    void selectSkill(std::string skillName);
    float attackWithWeapon(EquippedWeapon weapon); 
};

float VideoGameCharacter::EquippedWeapon::calculateDamage(EquippedWeapon currentWeapon)
{
    return (currentWeapon.minDamage + currentWeapon.maxDamage) / 2.0f + currentWeapon.addedStrengthAttribute;
}

bool VideoGameCharacter::EquippedWeapon::isEquippable(float weight, bool playerHasSpace)
{
    if (playerHasSpace == true && weight <= equippedWeight)
    {
        equippedWeight += weight;
        return true;
    }
    else
    {
        return false;
    }
}

float VideoGameCharacter::EquippedWeapon::durability(int numOfAttacksMade) 
{
    return addedStrengthAttribute -= float(numOfAttacksMade) / 100.f;
}

void VideoGameCharacter::castSpell(std::string spellName)
{
    std::cout << "Casting spell " << spellName << " on the target." << std::endl;
}

void VideoGameCharacter::selectSkill(std::string skillName)
{
    std::cout << "Selecting skill " << skillName << " for the character." << std::endl;
}

float VideoGameCharacter::attackWithWeapon(EquippedWeapon currentWeapon)
{
    currentWeapon.durability(1);
    return currentWeapon.calculateDamage(currentWeapon);
}

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

    void makeCoffee(std::string coffeeType);
    float sellCoffee(int numOfCups, float priceOfCoffee); 
    bool openAndCloseShop(int hour, bool isOpen);
};

void CoffeeShop::makeCoffee(std::string coffeeType)
{
    std::cout << "Brewing " << coffeeType << "." << std::endl;
    numOfCupsSoldPerDay += 1;
}

float sellCoffee(int numOfCups, float priceOfCoffee)
{
    return float(numOfCups) * priceOfCoffee;
}

bool CoffeeShop::openAndCloseShop(int hour, bool isOpen)
{
    if (hour < 6 || hour >= 22)
    {
        isOpen = false;
    }
    else 
    {
        isOpen = true;
    }
    return isOpen;
}
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
    bool igniteBurner();
    float preheat(float temperature); 
};

void BarbecueGrill::cookFood(std::string foodName)
{
    std::cout << "Cooking " << foodName << " on the grill." << std::endl;
}

bool BarbecueGrill::igniteBurner() 
{
    return true;
}

float BarbecueGrill::preheat(float temperature)
{
    if (temperature > currentTempInFarenheit)
    {   
        std::cout << "Increasing tmeperature to " << temperature << " degrees Farenheit." << std::endl;
    }

    else if (temperature < currentTempInFarenheit)
    {
        std::cout << "Decreasing tmeperature to " << temperature << " degrees Farenheit." << std::endl;
    }

    else
    {
        std::cout << "The grill has been preheated to " << temperature << " degrees Farenheit." << std::endl;
    }
    return currentTempInFarenheit = temperature;
}
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

    float accelerate(float acceleration, float time);
    bool ignite();
    bool activateTurbo();
};

float Engine::accelerate(float newAcceleration, float time)
{
    return velocity += newAcceleration * time;
}

bool Engine::ignite()
{
    return true;
}

bool Engine::activateTurbo()
{
    return true;
}

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

bool Wings::engageFlaps()
{
    return true;
}

float Wings::adjustAltitude(float altitudeAdjustment)
{
    return altitude += altitudeAdjustment;
}

void Wings::adjustPitchYawRoll(float newPitch, float newYaw, float newRoll)
{
    std::cout << "Adjusting pitch to " << newPitch << " degrees, yaw to " << newYaw << " degrees, and roll to " << newRoll << " degrees." << std::endl;
}

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

void Cockpit::signalCrewForTakeoff()
{
    std::cout << "Signaling crew for takeoff." << std::endl;
}

bool Cockpit::engageLandingGear()
{
    return true;
}

float Cockpit::adjustThrottle(float throttleAdjustment)
{
    return currentSpeedInKMPerHour += throttleAdjustment;
}
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
        float purchaseFirstClassSeat(int numOfFirstClassSeatsDesired);
        bool isFirstClassSectionFull(int numOfFirstClassSeatsPurchased);
    };

    void assignSeatsToPassengers(std::string passengerName);
    float storeLuggage(float luggageVolume);
    bool turnOnSeatbeltSign();

    FirstClassSection firstClassSection;
};

bool Cabin::FirstClassSection::engagePrivacyScreen(bool isPrivacyScreenEngaged)
{
    if (isPrivacyScreenEngaged != true) 
    {
        isPrivacyScreenEngaged = true;
    }
    return isPrivacyScreenEngaged;
}

float Cabin::FirstClassSection::purchaseFirstClassSeat(int numOfFirstClassSeatsDesired)
{
    return float(numOfFirstClassSeatsDesired) * priceOfFirstClassSeat;
}

bool Cabin::FirstClassSection::isFirstClassSectionFull(int numOfFirstClassSeatsPurchased)
{
    if (numOfFirstClassSeatsPurchased < numOfFirstClassSeats)
    {
        return false;
    }
    else if (numOfFirstClassSeatsPurchased > numOfFirstClassSeats)
    {
        std::cout << "Error, too many first class seats purchased." << std::endl;
        return true;
    }
    else
    {
        return true;
    }
}

void Cabin::assignSeatsToPassengers(std::string passengerName)
{
    std::cout << "Assigning seat " << seatNumber << " to passenger " << passengerName;
}

float Cabin::storeLuggage(float luggageVolume)
{
    if ((luggageVolume < overheadStorageBinCapacityInCubicMeters) && (overheadStorageBinCapacityInCubicMeters - luggageVolume > 0))
    {
        return overheadStorageBinCapacityInCubicMeters -= luggageVolume;
    }
    else
    {
        std::cout << "Error, luggage volume is too large." << std::endl;
        return overheadStorageBinCapacityInCubicMeters;
    }
}

bool Cabin::turnOnSeatbeltSign()
{
    return true;
}

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

    float fillStorage(float luggageVolume, float currentStorageVolume);
    float emptyStorage(float luggageVolume, float currentStorageVolume);
    bool checkStorageStatus(float storageCapacity, float totalLuggageWeight);
};

float Storage::fillStorage(float luggageVolume, float currentStorageVolume)
{

    if ((luggageVolume < currentStorageVolume) && (currentStorageVolume - luggageVolume > 0))
    {
        numOfStoredLuggage++;
        return currentStorageVolume -= luggageVolume;
    }
    else
    {
        std::cout << "Error, luggage volume is too large." << std::endl;
        return currentStorageVolume;
    }
}

float Storage::emptyStorage(float luggageVolume, float currentStorageVolume)
{
    numOfStoredLuggage--;
    return currentStorageVolume -= luggageVolume;
}

bool Storage::checkStorageStatus(float storageCapacity, float totalLuggageWeight)
{
    if (totalLuggageWeight < storageCapacity)
    {
        return false;
    }
    else
    {
        return true;
    }
}
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

float Airplane::accelerate(Engine engine)
{
    return engine.accelerate(engine.acceleration, 1.0f);
}

float Airplane::adjustAltitude(float altitudeAdjustment)
{
    return wings.adjustAltitude(altitudeAdjustment);
}

bool Airplane::liftoff()
{
    Airplane::adjustAltitude(10000.f);
    return wings.engageFlaps();
}

int main()
{
    std::cout << "good to go!" << std::endl;
}
