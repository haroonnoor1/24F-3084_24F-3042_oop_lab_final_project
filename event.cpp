#include "Stronghold.h"
#include <cstring>
using namespace std;

Event::Event(const char* type) {
    strcpy_s(eventType, sizeof(eventType), type ? type : "None");
}

void Event::triggerEvent() {
    cout << "Event triggered: " << eventType << "\n";
    if (strcmp(eventType, "Famine") == 0) {
       cout << "Famine has struck the kingdom. Resources are scarce.\n";
    }
    else if (strcmp(eventType, "War") == 0) {
        cout << "War has broken out. Armies are mobilizing.\n";
    }
    else if (strcmp(eventType, "Disease") == 0) {
       cout << "A plague has spread across the kingdom. Population is declining.\n";
    }
    else {
      cout << "An unexpected event has occurred.\n";
    }
}

void Event::update() {
   cout << "Updating event effects...\n";
}