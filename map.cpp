#include "Stronghold.h"
#include <iostream>
#include <cstdlib> // For rand()

// Constructor
Map::Map(int numRows, int numCols) : rows(numRows), cols(numCols) {
    // Initialize the map with empty spaces ('.')
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = '.';
        }
    }
}

// Initialize the map with terrain types
void Map::initializeMap() {
    // Example: Randomly assign terrain types
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int randomValue = rand() % 5; // Random number between 0 and 4
            switch (randomValue) {
            case 0:
                grid[i][j] = 'F'; // Forest
                break;
            case 1:
                grid[i][j] = 'M'; // Mountain
                break;
            case 2:
                grid[i][j] = 'P'; // Plains
                break;
            case 3:
                grid[i][j] = 'C'; // City
                break;
            default:
                grid[i][j] = '.'; // Empty space
            }
        }
    }
}

// Display the map on the console
void Map::displayMap() const {
    std::cout << "\n--- Kingdom Map ---\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Update the map state
void Map::update() {
    // Example: Simulate resource depletion or regeneration
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'F') {
                // Forest regenerates wood
                std::cout << "Forest at (" << i << ", " << j << ") regenerating wood.\n";
            }
            else if (grid[i][j] == 'M') {
                // Mountain regenerates stone and iron
                std::cout << "Mountain at (" << i << ", " << j << ") regenerating stone and iron.\n";
            }
        }
    }
}

// Get the terrain type at a specific cell
char Map::getCell(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return grid[row][col];
    }
    return '.'; // Return empty space if out of bounds
}

// Set the terrain type at a specific cell
void Map::setCell(int row, int col, char terrain) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        grid[row][col] = terrain;
    }
}