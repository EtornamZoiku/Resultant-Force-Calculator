#ifndef RESULTANTFORCECALCULATOR_H
#define RESULTANTFORCECALCULATOR_H

#include <vector>
#include "Force.h"

class ResultantForceCalculator {
public:
    // Constructor to initialize the ResultantForceCalculator object
    ResultantForceCalculator();
    // Method to add a new force to the list of forces
    void addForce(double magnitude, double direction);
    // Method to calculate the resultant force from the list of forces
    Force calculateResultantForce() const;

private:
    std::vector<Force> forces;  // Vector to store the forces
};

#endif // RESULTANTFORCECALCULATOR_H
