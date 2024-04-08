#include "ResultantForceCalculator.h"
#include <cmath>

ResultantForceCalculator::ResultantForceCalculator() {
    // Constructor: nothing to initialize here as the forces vector is automatically initialized
}

void ResultantForceCalculator::addForce(double magnitude, double direction) {
    Force force(magnitude, direction);
    forces.push_back(force);  // Add the force to the vector of forces
}

Force ResultantForceCalculator::calculateResultantForce() const {
    double x = 0.0;  // Initialize x-component of the resultant force
    double y = 0.0;  // Initialize y-component of the resultant force

    // Loop through each force in the vector and sum up the x and y components
    for (const Force& force : forces) {
        // Calculate the x and y components using trigonometric functions (cos and sin)
        x += force.getMagnitude() * std::cos(M_PI / 180.0 * force.getDirection());
        y += force.getMagnitude() * std::sin(M_PI / 180.0 * force.getDirection());
    }

    // Calculate the magnitude and direction of the resultant force using trigonometric functions
    double magnitude = std::sqrt(x * x + y * y);
    double direction = std::atan2(y, x) * 180.0 / M_PI;

    return Force(magnitude, direction);  // Return a new Force object representing the resultant force
}
