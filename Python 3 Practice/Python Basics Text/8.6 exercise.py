##Exercise 1
while True:
    try:
        value=int(input('Input an integer: '))
        if value==int(value):
            print(f'Your input is {value}. Thank you!')
        break
    except ValueError:
        print('Input an Integer, please!')

##Exercise 2
try:
    string=str(input("Type your favorite color:  "))
    n=int(input("Select a number equal to or fewer than \
the total amount of letters in the word: "))
    print(string[n-1])

except ValueError:
    print('Type an integer')
except IndexError:
    print('Select a number equal to or fewer than \
the total amount of letters in the word')

