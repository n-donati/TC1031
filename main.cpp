/*
/ NICOLAS DONATI
/ A01708256
*/

#include <iostream>
#include "bst.h"
#include "sort.h"
#include <fstream>

void displayMenu();
void displayCars(const std::vector<Car>& cars);
void saveToCSV(const std::vector<Car>& cars, const std::string& filename);
void addNewCar(BST<Car>& carBST);

int main() {
    BST<Car> carBST;
    carBST.loadFromCSV("porsche_models.csv");

    std::vector<Car> sortedByReleaseYear;
    std::vector<Car> sortedByMaxSpeed;
    std::vector<Car> sortedByModelName;
    bool sortedReleaseYear = false, sortedMaxSpeed = false, sortedModelName = false;

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
                sortedByReleaseYear = carBST.getSortedCars(compareByReleaseYear);
                displayCars(sortedByReleaseYear);
                sortedReleaseYear = true;
                break;
            case 2:
                sortedByMaxSpeed = carBST.getSortedCars(compareByMaxSpeed);
                displayCars(sortedByMaxSpeed);
                sortedMaxSpeed = true;
                break;
            case 3:
                sortedByModelName = carBST.inorder();
                displayCars(sortedByModelName);
                sortedModelName = true;
                break;
            case 4: {
                std::string modelToFind;
                std::cout << "Enter model to find: ";
                std::cin >> modelToFind;
                
                std::vector<Car> allCars = carBST.inorder();
                
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
            case 5:
                addNewCar(carBST);
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    if (sortedReleaseYear) {
        saveToCSV(sortedByReleaseYear, "sorted_by_release_year.csv");
    }
    if (sortedMaxSpeed) {
        saveToCSV(sortedByMaxSpeed, "sorted_by_max_speed.csv");
    }
    if (sortedModelName) {
        saveToCSV(sortedByModelName, "sorted_by_model_name.csv");
    }
   
    return 0;
}

void displayMenu() {
    std::cout << "\nPorsche Models Menu:\n";
    std::cout << "1. Sort by release year\n";
    std::cout << "2. Sort by max speed\n";
    std::cout << "3. Sort by model name\n";
    std::cout << "4. Search by model name\n";
    std::cout << "5. Add a new car\n";
    std::cout << "0. Exit and save files\n";
    std::cout << "Enter your choice: ";
}

void displayCars(const std::vector<Car>& cars) {
    std::cout << "\nSorted Porsche Models:\n";
    for (const auto& car : cars) {
        std::cout << car << std::endl;
    }
}

void saveToCSV(const std::vector<Car>& cars, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    file << "Model,ReleaseYear,MaxSpeed\n";
    for (const auto& car : cars) {
        file << car.getModel() << "," << car.getReleaseYear() << "," << car.getMaxSpeed() << "\n";
    }
    file.close();
}

void addNewCar(BST<Car>& carBST) {
    std::string model;
    int releaseYear;
    double maxSpeed;

    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter release year: ";
    std::cin >> releaseYear;
    std::cout << "Enter max speed: ";
    std::cin >> maxSpeed;

    Car newCar(model, releaseYear, maxSpeed);
    carBST.add(newCar);
    std::cout << "Car added successfully.\n";
}
