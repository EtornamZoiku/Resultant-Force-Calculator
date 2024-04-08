#include <iostream>
#include "ResultantForceCalculator.h"

using namespace std;

//Create a function named 'WelcomeMessage' to print a welcome message
void WelcomeMessage() {
    cout << "======================================================================================================================\n";
    cout << "                                WELCOME TO THE RESULTANT FORCE CALCULATION PROGRAM\n";
    cout << "======================================================================================================================\n";
    cout << "\n";
}

int main() {
    // Call the WelcomeMessage function to display the welcome message
    WelcomeMessage();

    // Create an instance of the ResultantForceCalculator class
    ResultantForceCalculator calculator;

    string choice = "y"; // Initialize the choice to continue
    while (choice == "y" || choice == "Y" || choice == "YES" || choice == "yes") {

        // Prompt the user to enter the number of forces
        int num_forces;
        cout << "Please enter the number of forces whose resultant you want to find: ";
        cin >> num_forces;

        // Validate num_forces
        while (num_forces <= 1) {
            cout << num_forces << " is invalid. Please enter a positive integer greater than 1: ";
            cin >> num_forces;
        }
        cout << "\n";

        // Get magnitude and direction for each force and add it to the calculator
        for (int i = 0; i < num_forces; ++i) {
            double magnitude, direction;

            // Prompt the user to enter the magnitude of force i + 1 and its direction
            cout << "Enter the magnitude of force " << i + 1 << ": ";
            cin >> magnitude;

            // Validate the magnitude
            while (magnitude <= 0) {
                    cout << magnitude << " is invalid. Please enter a positive number greater than 0: ";
                    cin >> magnitude;
                    cout << "\n";
            }

            // Prompt the user to enter the direction
            cout << "What is its direction in degrees? ";
            cin >> direction;
            cout << "\n";

            // Validate the direction
            while (direction < 0 || direction > 360) {
                cout << direction << " is invalid. Please enter a positive number in the range 0 <= direction <= 360: ";
                cin >> direction;
                cout << "\n";
            }

            // Add the force to the list of forces
            calculator.addForce(magnitude, direction);
        }

        // Calculate the resultant force
        Force resultant_force = calculator.calculateResultantForce();

        // Display the magnitude and direction of the resultant force
        cout << "Magnitude of Resultant Force: " << resultant_force.getMagnitude() << " units" << endl;
        cout << "Direction of Resultant Force: " << resultant_force.getDirection() << " degrees" << endl;
        cout << "\n";

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        cout << "\n";

    }

    return 0;
}
