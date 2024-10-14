/*
/ NICOLAS DONATI
/ A01708256
*/

#include <iostream>
#include "bst.h"
#include "sort.h"

void displayMenu();
void displayCars(const std::vector<Car>& cars);

int main() {
    BST<Car> carBST;
    carBST.loadFromCSV("porsche_models.csv");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = -1;
        }
       
        std::vector<Car> sortedCars;
        switch (choice) {
            case 1:
                sortedCars = carBST.getSortedCars(compareByReleaseYear);
                displayCars(sortedCars);
                break;
            case 2:
                sortedCars = carBST.getSortedCars(compareByMaxSpeed);
                displayCars(sortedCars);
                break;
            case 3:
                sortedCars = carBST.getSortedCars(compareByModelName);
                displayCars(sortedCars);
                break;
            case 4: {
                std::string modelToFind;
                std::cout << "Enter model to find: ";
                std::cin >> modelToFind;
                
                std::vector<Car> allCars = carBST.getSortedCars(compareByModelName);
                
                bool found = false;
                for (const Car& car : allCars) {
                    if (car.getModel() == modelToFind) {
                        std::cout << "Car found: " << car << std::endl;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    std::cout << "Car not found.\n";
                }
                break;
            }

            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
   
    return 0;
}

void displayMenu() {
    std::cout << "\nPorsche Models Menu:\n";
    std::cout << "1. Sort by release year\n";
    std::cout << "2. Sort by max speed\n";
    std::cout << "3. Sort by model name\n";
    std::cout << "4. Find model\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void displayCars(const std::vector<Car>& cars) {
    std::cout << "\nSorted Porsche Models:\n";
    for (const auto& car : cars) {
        std::cout << car << std::endl;
    }
}
