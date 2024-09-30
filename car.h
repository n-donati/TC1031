// car.h
#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Car {
private:
    std::string model;
    int releaseYear;
    double maxSpeed;

public:
    Car();
    Car(const std::string& model, int releaseYear, double maxSpeed);
    ~Car();

    std::string getModel() const;
    int getReleaseYear() const;
    double getMaxSpeed() const;

    void setModel(const std::string& model);
    void setReleaseYear(int releaseYear);
    void setMaxSpeed(double maxSpeed);

    bool operator<(const Car& other) const;
    bool operator>(const Car& other) const;
    bool operator==(const Car& other) const;

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};

// car.cpp
Car::Car(const std::string& model, int releaseYear, double maxSpeed)
    : model(model), releaseYear(releaseYear), maxSpeed(maxSpeed) {}

Car::Car() : model("NA"), releaseYear(0), maxSpeed(0.0) {}

Car::~Car() {}

// Getters
std::string Car::getModel() const { return model; }
int Car::getReleaseYear() const { return releaseYear; }
double Car::getMaxSpeed() const { return maxSpeed; }

// Setters
void Car::setModel(const std::string& newModel) { model = newModel; }
void Car::setReleaseYear(int newReleaseYear) { releaseYear = newReleaseYear; }
void Car::setMaxSpeed(double newMaxSpeed) { maxSpeed = newMaxSpeed; }

// Operators
bool Car::operator<(const Car& other) const { return this->maxSpeed < other.maxSpeed; }
bool Car::operator>(const Car& other) const { return this->maxSpeed > other.maxSpeed; }
bool Car::operator==(const Car& other) const {
    return this->model == other.model &&
           this->releaseYear == other.releaseYear &&
           this->maxSpeed == other.maxSpeed;
}

std::string Car::toString() const {
    std::ostringstream oss;
    oss << "Modelo: " << model
        << ", Año: " << releaseYear
        << ", Velocidad Máxima: " << std::fixed << std::setprecision(2) << maxSpeed << " km/h";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << car.toString();
    return os;
}

#endif // CAR_H