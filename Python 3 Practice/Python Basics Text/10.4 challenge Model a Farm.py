# In this assignment, you’ll create a simplified model of a farm. 
# As you work through this assignment, keep in mind that there are a number of correct answers.

# The focus of this assignment is less about the Python class syntax and more about software design 
# in general, which is highly subjective. 
# This assignment is intentionally left open-ended to encourage you to think about how you would 
# organize your code into classes.

# Before you write any code, grab a pen and paper and sketch out a model of your farm, 
# identifying classes, attributes, and methods. 
# Think about inheritance. How can you prevent code duplication? 
# Take the time to work through as many iterations as you feel are necessary.

# The actual requirements are open to interpretation, but try to adhere to these guidelines:

# 1.You should have at least four classes: the parent Animal class, and then 
# at least three child animal classes that inherit from Animal.

# 2. Each class should have a few attributes 
# and at least one method that models some behavior appropriate for a specific animal or all animals
# —such as walking, running, eating, sleeping, and so on.

# 3. Keep it simple. Utilize inheritance. 
# Make sure you output details about the animals and their behaviors.

class Animal:
    def __init__(self, animal, coat_color, legs):
        self.animal = animal
        self.coat_color = coat_color
        self.legs = legs
    def speak(self, sound):
        return f'The {self.animal} says {sound}!'
    def eat(self):
        return f'The {self.animal} is eating'
    def sleep(self):
        return f'The {self.animal} is sleeping. Zzzzzzzz'

class Horse(Animal):
    def speak(self, sound="Neighhhh"):
        return super().speak(sound)
    def ride(self):
        return f'You are taking your {self.animal} for a ride!'

class Cow(Animal):
    def speak(self, sound="Mooooooo"):
        return super().speak(sound)
    def milk(self):
        return f'You are milking your {self.animal}!'

class Pig(Animal):
    def speak(self, sound="Oink"):
        return super().speak(sound)
    def mud(self):
        return f'Your {self.animal} rolls in the mud!'

horse = Horse("Horse", "brown", 4)
pig = Pig("Pig", "brown", 4)
cow = Cow("Cow", "black and white", 4)

print(horse.speak())
print(horse.speak("winnyyy"))
print(cow.speak())
print(horse.eat())
print(cow.eat())
print(cow.sleep())
print(pig.sleep())
print(pig.speak())
print(horse.ride())
print(cow.milk())
print(pig.mud())