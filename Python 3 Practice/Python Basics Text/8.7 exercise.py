##Exercise 1

from random import randint

def roll():
    """Returns a value 1-6, as in rolling a 6-sided die"""
    return randint(1, 6)

##Exercise 2

while True:
    try:
        num_rolls = int(input("How many times to roll?  "))
        print(f'Proceeding to roll {num_rolls} times.')
        break
    except ValueError:
        print("Invalid integer.")
        
total = 0

for trial in range(num_rolls):
    total = total + roll()
   
avg_roll = total / num_rolls
print(avg_roll)
