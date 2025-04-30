#include "Stronghold.h"

using namespace std;

Army::Army(int initialSoldiers) : soldiers(initialSoldiers), morale(100), isCorrupt(false) {}

void Army::train() {
    soldiers += 10;
    morale += 5;
    cout << "Army trained. Soldiers increased by 10. Morale increased by 5.\n";
}

void Army::pay() {
    morale += 10;
    cout << "Army paid. Morale increased by 10.\n";
}

void Army::decreaseMorale() {
    morale -= 10;
    cout << "Army morale decreased by 10 due to lack of resources or corruption.\n";
}

void Army::feed(int foodConsumption) {
    if (foodConsumption >= soldiers * 2) {
        morale += 5;
        cout << "Army fed properly. Morale increased by 5.\n";
    }
    else {
        morale -= 10;
        cout << "Army not fed properly. Morale decreased by 10.\n";
    }
}

void Army::update() {
    if (morale <= 0) {
        cout << "Warning: Army morale has collapsed!\n";
    }
}

int Army::getSoldiers() const {
    return soldiers;
}