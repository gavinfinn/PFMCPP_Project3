/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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
    return false;
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
    }
    return true;
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
    return true;
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
    Example::main();

    //add your code between these lines
    //=================================


    
    //=================================
    std::cout << "good to go!" << std::endl;
}
