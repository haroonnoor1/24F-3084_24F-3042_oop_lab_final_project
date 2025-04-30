#include "Stronghold.h"
#include <cstring>
#include <iostream>

// Constructor
Leadership::Leadership(const char* initialLeaderName, int initialStyle)
    : leadershipStyle(initialStyle), isCoupAttempted(false) {
    strncpy_s(leaderName, sizeof(leaderName), initialLeaderName, _TRUNCATE);
}

// Elect a new leader
void Leadership::electLeader(const char* newLeaderName, int newStyle) {
    if (newStyle < 1 || newStyle > 3) {
        std::cerr << "Error: Invalid leadership style. Must be 1 (Benevolent), 2 (Authoritarian), or 3 (Corrupt).\n";
        return;
    }
    strncpy_s(leaderName, sizeof(leaderName), newLeaderName, _TRUNCATE);
    leadershipStyle = newStyle;
    std::cout << "New leader elected: " << leaderName << " with style ";
    switch (leadershipStyle) {
    case 1:
        std::cout << "Benevolent.\n";
        break;
    case 2:
        std::cout << "Authoritarian.\n";
        break;
    case 3:
        std::cout << "Corrupt.\n";
        break;
    }
}

// Attempt a coup
void Leadership::attemptCoup() {
    if (isCoupAttempted) {
        std::cerr << "Error: A coup has already been attempted recently.\n";
        return;
    }
    isCoupAttempted = true;
    std::cout << "A coup has been attempted against " << leaderName << "!\n";
    if (leadershipStyle == 3) { // Corrupt leaders are more likely to fail
        std::cout << "The coup succeeded! The corrupt leader has been overthrown.\n";
        strncpy_s(leaderName, sizeof(leaderName), "Interim Leader", _TRUNCATE);
        leadershipStyle = 1; // Default to Benevolent after a coup
    }
    else {
        std::cout << "The coup failed. The current leader remains in power.\n";
    }
}

// Implement policies based on leadership style
void Leadership::implementPolicy() {
    std::cout << leaderName << " is implementing policies...\n";
    switch (leadershipStyle) {
    case 1: // Benevolent
        std::cout << "Focus: Welfare programs, reduced taxes, and improved living conditions.\n";
        break;
    case 2: // Authoritarian
        std::cout << "Focus: Military expansion, strict laws, and increased taxation.\n";
        break;
    case 3: // Corrupt
        std::cout << "Focus: Embezzlement, favoritism, and exploitation of resources.\n";
        break;
    }
}

// Update leadership status
void Leadership::update() {
    if (isCoupAttempted) {
        std::cout << "Warning: Political instability due to recent coup attempt.\n";
    }
}

// Get the current leader's name
const char* Leadership::getLeaderName() const {
    return leaderName;
}