#include "Force.h"

Force::Force(double magnitude, double direction)
    : magnitude(magnitude), direction(direction){
    // Constructor: Initialize the magnitude and direction of the force
}

double Force::getMagnitude() const{
    return magnitude;  // Getter method: return the magnitude of the force
}

double Force::getDirection() const
{
    return direction;  // Getter method: return the direction of the force in degrees
}
