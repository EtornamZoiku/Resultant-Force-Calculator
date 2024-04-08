# Import the math module to access trigonometric functions
import math

# Create a class named "Force" to represent a force with magnitude and direction
class Force:
    def __init__(self, magnitude, direction):
        self.magnitude = magnitude  # Initialize the magnitude of the force
        self.direction = direction  # Initialize the direction of the force

# Create a class named "ResultantForceCalculator" to handle multiple forces and calculate the resultant force
class ResultantForceCalculator:
    def __init__(self):
        self.forces = []  # Initialize an empty list to store the forces

    # Method to add a new force to the list of forces
    def add_force(self, magnitude, direction):
        force = Force(magnitude, direction)  # Create a new Force object with the given magnitude and direction
        self.forces.append(force)  # Append the new force to the list of forces

    # Method to calculate the resultant force from the list of forces
    def calculate_resultant_force(self):
        x = 0  # Initialize x-component of the resultant force
        y = 0  # Initialize y-component of the resultant force

        # Loop through each force in the list of forces and sum up the x and y components
        for force in self.forces:
            # Calculate the x and y components using trigonometric functions (cos and sin)
            x += force.magnitude * math.sin(math.radians(force.direction))
            y += force.magnitude * math.sin(math.radians(force.direction))

        # Calculate the magnitude and direction of the resultant force using trigonometric functions
        magnitude = math.sqrt(x**2 + y**2)
        direction = math.degrees(math.atan2(y, x))

        return Force(magnitude, direction)  # Return a new Force object representing the resultant force

# Define a function named 'WelcomeMessage' to print a welcome message
def WelcomeMessage():
    print("=============================================================================================================================================================")
    print("                                           WELCOME TO THE RESULTANT FORCE CALCULATION PROGRAM                                                                ")
    print("=============================================================================================================================================================")

# Check if the script is being run as the main program
if __name__ == "__main__":
    choice = 'y'  # Initialize the choice to continue
    WelcomeMessage()  # Call the WelcomeMessage function to display the welcome message

    # Continue the loop as long as the user's choice is 'y' or 'yes'
    while choice.strip().lower() in ["y", "yes"]:
        calculator = ResultantForceCalculator()  # Create an instance of the ResultantForceCalculator class

        # Prompt the user to enter the number of forces
        num_forces = int(input("Please enter the number of forces whose resultant you want to find: "))

        # Validate num_forces
        while num_forces <= 1:
            num_forces = int(input(f"{num_forces} is invalid. Please enter a positive integer greater than 1: "))

        # Get magnitude and direction for each force and add it to the calculator
        for i in range(num_forces):

            # Prompt the user to enter the magnitude
            magnitude = float(input(f"Enter the magnitude of the force {i + 1}: "))

            # Validate the magnitude
            while magnitude <= 0:
                magnitude = float(input(f"{magnitude} is invalid. Please enter a positive number: "))

            # Prompt the user to enter the direction
            direction = float(input("What is its direction in degrees? "))

            # Validate the direction
            while direction < 0 or direction > 360:
                direction = float(input(f"{direction} is invalid. Please enter a positive number in the range 0 <= direction <= 360: "))
            print("\n")

            # Add the force to the list of forces
            calculator.add_force(magnitude, direction)

        # Calculate the resultant force
        resultant_force = calculator.calculate_resultant_force()

        # Display the magnitude and direction of the resultant force
        print("Magnitude of Resultant Force:", resultant_force.magnitude, "units")
        print("Direction of Resultant Force:", resultant_force.direction, "degrees")
        print("\n")

        # Ask the user if they want to continue
        choice = input("Do you want to continue? (y/n): ")
        print("\n")
