#ifndef FORCE_H
#define FORCE_H

class Force {
public:
    // Constructor to initialize the Force object with magnitude and direction
    Force(double magnitude, double direction);
    // Getter methods to access magnitude and direction
    double getMagnitude() const;
    double getDirection() const;

private:
    double magnitude;  // Magnitude of the force
    double direction;  // Direction of the force in degrees
};

#endif // FORCE_H
