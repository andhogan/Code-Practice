import random

def coin_flip():
    """Returns value of a fair coin Heads or Tails"""
    if random.randint(0, 1) == 0:
        return "heads"
    else:
        return "tails"

flips = 0

while True:
    try:
        num_trials = int(input('How many times will you flip a coin?  '))
        break
    except ValueError:
        print('Input an integer.')

for trials in range(num_trials):
    if coin_flip() == "heads":
        flips = flips + 1
        while coin_flip() == "heads":
            flips = flips + 1
        flips = flips + 1
    else:
        flips = flips + 1
        while coin_flip() == "tails":
            flips = flips + 1
        flips = flips + 1

avg_flips_per_trial = flips / num_trials
print(f'The average number of flips per trial is {avg_flips_per_trial}.')
