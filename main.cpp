#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "car.h"
#include "sort.h"
 
void loadCarsFromCSV(const std::string& filename, std::vector<Car>& cars);
void displayMenu();
void sortCars(std::vector<Car>& cars, int choice);
void displayCars(const std::vector<Car>& cars);

int main() {
    std::vector<Car> cars;
    loadCarsFromCSV("porsche_models.csv", cars);
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        if (choice >= 1 && choice <= 3) {
            sortCars(cars, choice);
            displayCars(cars);
        } else if (choice != 4) {
            std::cout << "Elección no válida. Inténtalo de nuevo.\n";
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "\nMenú de Ordenación de Modelos Porsche:\n";
    std::cout << "1. Ordenar por fecha de lanzamiento\n";
    std::cout << "2. Ordenar por velocidad máxima\n";
    std::cout << "3. Ordenar por nombre del modelo\n";
    std::cout << "4. Salir\n";
    std::cout << "Introduzca su elección: ";
}

void loadCarsFromCSV(const std::string& filename, std::vector<Car>& cars) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string model;
        int year;
        double speed;
        if (std::getline(iss, model, ',') &&
            iss >> year &&
            iss.ignore() &&
            iss >> speed) {
            cars.emplace_back(model, year, speed);
        }
    }
    file.close();
}

void sortCars(std::vector<Car>& cars, int choice) {
    switch (choice) {
        case 1:
            sortByReleaseYear(cars);
            break;
        case 2:
            sortByMaxSpeed(cars);
            break;
        case 3:
            sortByModelName(cars);
            break;
    }
}

void displayCars(const std::vector<Car>& cars) {
    std::cout << "\nModelos Porsche Ordenados:\n";
    for (const auto& car : cars) {
        std::cout << car << std::endl;
    }
}