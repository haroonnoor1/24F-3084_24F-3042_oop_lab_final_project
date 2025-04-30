#ifndef STRONGHOLD_H
#define STRONGHOLD_H

#include <iostream>
#include <fstream>
#include <cstring>

// Base class for all systems
class System {
public:
    virtual void update() = 0; // Pure virtual function for system updates
    virtual ~System() = default;
};

// Template for general-purpose data handling
template <typename T>
class DataHandler {
private:
    T data;
public:
    DataHandler(T initialData) : data(initialData) {}
    void updateData(T newData) { data = newData; }
    T getData() const { return data; }
};

// Population class
class Population : public System {
private:
    int totalPopulation;
    int peasants;
    int merchants;
    int nobles;
    bool isRevolted;

public:
    Population(int initialPopulation = 100);
    void grow();
    void shrink();
    void revolt();
    void starve(int foodDeficit);
    void update() override;
    int getTotalPopulation() const;
};

// Army class
class Army : public System {
private:
    int soldiers;
    int morale;
    bool isCorrupt;

public:
    Army(int initialSoldiers = 50);
    void train();
    void pay();
    void decreaseMorale();
    void feed(int foodConsumption);
    void update() override;
    int getSoldiers() const;
};

// Economy class
class Economy : public System {
private:
    double treasury;
    double taxRate;
    bool isInflation;

public:
    Economy(double initialTreasury = 1000.0);
    void collectTax(double amount);
    void spend(double amount);
    void handleInflation();
    void update() override;
    double getTreasury() const;
};

// Bank class
class Bank : public System {
private:
    double loans;
    double interestRate;

public:
    Bank(double initialLoans = 0.0, double initialInterestRate = 0.05);
    void giveLoan(double amount);
    void audit();
    void update() override;
    double getLoans() const;
};

// Resource class
class Resource : public System {
private:
    int food;
    int wood;
    int stone;
    int iron;

public:
    Resource(int initialFood = 100, int initialWood = 50, int initialStone = 50, int initialIron = 20);
    void gatherResources();
    void consumeResources(int foodConsumption, int woodConsumption, int stoneConsumption, int ironConsumption);
    void distributeFood(Population& population, Army& army);
    void update() override;
    int getFood() const;
};

// Event class
class Event : public System {
private:
    char eventType[20]; // Fixed-size array instead of std::string

public:
    Event(const char* type = "None");
    void triggerEvent();
    void update() override;
};

// Leadership class
class Leadership : public System {
private:
    char leaderName[20];
    int leadershipStyle; // 1: Benevolent, 2: Authoritarian, 3: Corrupt
    bool isCoupAttempted;

public:
    Leadership(const char* initialLeaderName = "King", int initialStyle = 1);
    void electLeader(const char* newLeaderName, int newStyle);
    void attemptCoup();
    void implementPolicy();
    void update() override;
    const char* getLeaderName() const;
};

// Map class
class Map : public System {
private:
    int rows; // Number of rows in the map
    int cols; // Number of columns in the map
    char grid[20][20]; // Fixed-size 2D array representing the map

public:
    Map(int numRows = 10, int numCols = 10); // Constructor
    void initializeMap(); // Initialize the map with terrain types
    void displayMap() const; // Display the map on the console
    void update() override; // Update the map state
    char getCell(int row, int col) const; // Get the terrain type at a specific cell
    void setCell(int row, int col, char terrain); // Set the terrain type at a specific cell
};

#endif // STRONGHOLD_H