#include "Stronghold.h"

Bank::Bank(double initialLoans, double initialInterestRate) : loans(initialLoans), interestRate(initialInterestRate) {}

void Bank::giveLoan(double amount) {
    if (amount <= 0) {
        std::cerr << "Error: Loan amount must be positive.\n";
        return;
    }
    loans += amount;
    std::cout << "Loan granted: " << amount << ". Total loans: " << loans << "\n";
}

void Bank::audit() {
    if (loans > 1000.0) {
        std::cout << "Audit result: Loans exceed safe limit. Interest rate increased.\n";
        interestRate += 0.02; // Increase interest rate by 2%
    }
    else {
        std::cout << "Audit result: Financial health is stable.\n";
    }
}

void Bank::update() {
    if (loans > 0) {
        loans += loans * interestRate; // Apply interest
        std::cout << "Interest applied. Total loans: " << loans << "\n";
    }
}

double Bank::getLoans() const {
    return loans;
}