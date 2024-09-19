#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

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

#endif