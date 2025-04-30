#include "Stronghold.h"

using namespace std;

Resource::Resource(int initialFood, int initialWood, int initialStone, int initialIron)
    : food(initialFood), wood(initialWood), stone(initialStone), iron(initialIron) {
}

void Resource::gatherResources() {
    food += 10; // Simulate food gathering
    wood += 5;  // Simulate wood gathering
    stone += 3; // Simulate stone gathering
    iron += 2;  // Simulate iron gathering
    cout << "Resources gathered: Food +10, Wood +5, Stone +3, Iron +2.\n";
}

void Resource::consumeResources(int foodConsumption, int woodConsumption, int stoneConsumption, int ironConsumption) {
    food -= foodConsumption;
    wood -= woodConsumption;
    stone -= stoneConsumption;
    iron -= ironConsumption;
    cout << "Resources consumed: Food -" << foodConsumption << ", Wood -" << woodConsumption
        << ", Stone -" << stoneConsumption << ", Iron -" << ironConsumption << "\n";
}

void Resource::distributeFood(Population& population, Army& army) {
    int totalFoodNeeded = population.getTotalPopulation() * 2 + army.getSoldiers() * 2;
    if (food >= totalFoodNeeded) {
        food -= totalFoodNeeded;
        cout << "Distributed " << totalFoodNeeded << " units of food to population and army.\n";
    }
    else {
        cout << "Not enough food to distribute. Starvation may occur.\n";
    }
}

void Resource::update() {
    gatherResources(); // Simulate resource gathering during updates
}

int Resource::getFood() const {
    return food;
}