#include "Stronghold.h"

using namespace std;

Population::Population(int initialPopulation)
    : totalPopulation(initialPopulation), peasants(0), merchants(0), nobles(0), isRevolted(false) {
    peasants = initialPopulation * 60 / 100; // 60% peasants
    merchants = initialPopulation * 30 / 100; // 30% merchants
    nobles = initialPopulation * 10 / 100; // 10% nobles
}

void Population::grow() {
    totalPopulation += 5;
    peasants += 3; // Peasants grow faster
    merchants += 1;
    nobles += 1;
    cout << "Population grew by 5. Total population: " << totalPopulation << "\n";
}

void Population::shrink() {
    totalPopulation -= 5;
    peasants -= 3; // Peasants are most affected
    merchants -= 1;
    nobles -= 1;
    cout << "Population shrank by 5. Total population: " << totalPopulation << "\n";
}

void Population::revolt() {
    isRevolted = true;
    totalPopulation -= 20; // Revolt causes significant loss
    peasants -= 15;
    merchants -= 3;
    nobles -= 2;
    cout << "Revolt occurred. Population decreased by 20.\n";
}

void Population::starve(int foodDeficit) {
    int deaths = foodDeficit / 2; // Each death corresponds to 2 units of missing food
    if (deaths > totalPopulation) {
        deaths = totalPopulation; // Cap deaths at total population
    }

    totalPopulation -= deaths;
    peasants -= deaths * 60 / 100; // Proportionally reduce peasants
    merchants -= deaths * 30 / 100; // Proportionally reduce merchants
    nobles -= deaths * 10 / 100; // Proportionally reduce nobles

    cout << "Starvation occurred. " << deaths << " people died. Remaining population: " << totalPopulation << "\n";
}

void Population::update() {
    if (totalPopulation <= 0) {
        cout << "Warning: Population has collapsed!\n";
    }
}

int Population::getTotalPopulation() const {
    return totalPopulation;
}