#include "Stronghold.h"

using namespace std;

// Save game state to a file
void saveGameState(const char* filename, const Population& population, const Army& army, const Economy& economy, const Bank& bank, const Resource& resource) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Failed to open file for saving game state.\n";
        return;
    }

    outFile << "Population: " << population.getTotalPopulation() << "\n";
    outFile << "Soldiers: " << army.getSoldiers() << "\n";
    outFile << "Treasury (Gold): " << economy.getTreasury() << "\n";
    outFile << "Loans: " << bank.getLoans() << "\n";
    outFile << "Food: " << resource.getFood() << "\n";

    outFile.close();
    cout << "Game saved successfully to " << filename << ".\n";
}

int main() {
    // Initialize game systems
    Population population(100);
    Army army(50);
    Economy economy(1000.0);
    Bank bank(0.0, 0.05);
    Resource resource(100, 50, 50, 20); // Initial food = 100
    Leadership leadership("King Arthur", 1);
    Map map(10, 10); // 10x10 map
    map.initializeMap();

    // Game loop
    while (true) {
        // Display menu with ASCII art
        

        cout << "-- - Stronghold Game-- -" << endl;;
             cout <<"1.View Kingdom Status(Food, Gold, Army)" << endl;
             cout <<"2.Train Army" << endl;
             cout <<"3. Collect Tax" << endl;
             cout <<"4.Distribute Food" << endl;
             cout <<"5.Manage Treasury" << endl;
             cout <<"6.Elect New Leader" << endl;
             cout <<"7.Attempt Coup" << endl;
             cout <<"8.Implement Policies" << endl;
             cout <<"9.Trigger Random Event" << endl;
             cout <<"10.View Kingdom Map" << endl;
             cout <<"11.Save Game"<<endl;
             cout <<"12.Exit" << endl;


             cout << "Enter your choice";


        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Display kingdom status: Food, Gold, Army
            population.update();
            cout << "\n--- Kingdom Status ---\n";
            cout << "Total Population: " << population.getTotalPopulation() << "\n";
            cout << "Current Treasury (Gold): " << economy.getTreasury() << "\n";
            cout << "Current Food Stockpile: " << resource.getFood() << "\n";
            cout << "Current Soldiers: " << army.getSoldiers() << "\n";
            break;
        }

        case 2:
            army.train();
            army.update();
            cout << "Soldiers trained. Total soldiers: " << army.getSoldiers() << "\n";
            break;

        case 3:
            economy.collectTax(100.0);
            economy.update();
            cout << "Tax collected. Treasury (Gold): " << economy.getTreasury() << "\n";
            break;

        case 4:
            resource.distributeFood(population, army);
            resource.update();
            cout << "Food distributed to population and army.\n";
            break;

        case 5: { // Manage Treasury Option
            cout << "Current Treasury Balance (Gold): " << economy.getTreasury() << "\n";
            cout << "1. Spend from Treasury\n";
            cout << "2. View Treasury\n";
            cout << "Enter your choice: ";
            int treasuryChoice;
            cin >> treasuryChoice;

            if (treasuryChoice == 1) {
                cout << "Enter amount to spend (Gold): ";
                double amount;
                cin >> amount;
                if (amount > economy.getTreasury()) {
                    cout << "Insufficient funds in treasury. Cannot spend " << amount << " gold.\n";
                }
                else {
                    economy.spend(amount);
                    economy.update();
                    cout << "Treasury (Gold) after spending: " << economy.getTreasury() << "\n";
                }
            }
            else if (treasuryChoice == 2) {
                cout << "Current Treasury Balance (Gold): " << economy.getTreasury() << "\n";
            }
            else {
                cerr << "Invalid choice. Returning to main menu.\n";
            }
            break;
        }

        case 6: {
            char newLeaderName[20];
            int newStyle;
            cout << "Enter new leader's name: ";
            cin >> newLeaderName;
            cout << "Enter leadership style (1: Benevolent, 2: Authoritarian, 3: Corrupt): ";
            cin >> newStyle;
            leadership.electLeader(newLeaderName, newStyle);
            cout << "New leader elected: " << leadership.getLeaderName() << "\n";
            break;
        }

        case 7:
            leadership.attemptCoup();
            leadership.update();
            cout << "Coup attempt executed.\n";
            break;

        case 8:
            leadership.implementPolicy();
            cout << "Policy implemented by the leader.\n";
            break;

        case 9: {
            Event event;
            event.triggerEvent();
            event.update();
            cout << "Random event triggered.\n";
            break;
        }

        case 10: // View Kingdom Map
            map.displayMap();
            map.update();
            break;

        case 11: // Save Game
            saveGameState("game_save.txt", population, army, economy, bank, resource);
            break;

        case 12: // Exit
            cout << "Exiting game...\n";
            return 0;

        default:
            cerr << "Invalid choice. Try again.\n";
        }
    }
}