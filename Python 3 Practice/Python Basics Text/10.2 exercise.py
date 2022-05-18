# Exercise 1
# Modify the Dog class to include a third instance attribute called coat_color 
# that stores the color of the dog’s coat as a string. 
# Store your new class in a script and test it out by adding the 
# following code at the bottom of the script:

# philo = Dog("Philo", 5, "brown")
# print(f"{philo.name}'s coat is {philo.coat_color}.")

# The output of your script should be:

# Philo's coat is brown.

class Dog:
    def __init__(self, name, age, coat_color):
        self.name = name
        self.age = age
        self.coat_color = coat_color

philo = Dog("Philo", 5, "brown")
print(f"{philo.name}'s coat is {philo.coat_color}.")

# Exercise 2
# Create a Car class with two instance attributes: 
# .color, which stores the name of the car’s color as a string, and 
# .mileage, which stores the number of miles on the car as an integer. 
# Then instantiate two Car object—
# a blue car with 20,000 miles, and 
# a red car with 30,000 miles, and 
# print out their colors and mileage. 

# Your output should look like the following:
#The blue car has 20,000 miles.
#The red car has 30,000 miles.

class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage
    
    def drive(self, drive_mileage):
        self.mileage += drive_mileage
        return self.mileage

blue_car = Car("blue", 20000)
red_car = Car("red", 30000)

print(f'The {blue_car.color} car has {blue_car.mileage} miles.')
print(f'The {red_car.color} car has {red_car.mileage} miles.')

# Exercise 3
# Modify the Car class with an instance method called .drive() that takes a number as an argument and adds that number to the .mileage attribute. 
# Test that your solution works by instantiating a car with 0 miles, then 
# call .drive(100) and print the .mileage attribute to check that it is set to 100.

new_car = Car("black", 0)
new_car.drive(100)
print(f'The {new_car.color} car has {new_car.mileage} miles.')