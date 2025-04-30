#include "Stronghold.h"

using namespace std;

Economy::Economy(double initialTreasury) : treasury(initialTreasury), taxRate(0.1), isInflation(false) {}

void Economy::collectTax(double amount) {
    treasury += amount;
    cout << "Collected tax of " << amount << " gold. New treasury balance: " << treasury << "\n";
}

void Economy::spend(double amount) {
    treasury -= amount;
    cout << "Spent " << amount << " gold. Remaining treasury balance: " << treasury << "\n";
}

void Economy::handleInflation() {
    if (isInflation) {
        treasury *= 0.9; // Reduce treasury by 10% due to inflation
        cout << "Inflation occurred. Treasury reduced by 10%. New balance: " << treasury << "\n";
    }
}

void Economy::update() {
    handleInflation(); // Simulate inflation effects during updates
}

double Economy::getTreasury() const {
    return treasury;
}