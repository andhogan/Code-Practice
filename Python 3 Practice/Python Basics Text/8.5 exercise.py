##Exercise 1
while True:
    user_input=str(input("Enter 'Q' to quit this program:  "))
    user_input=user_input.upper()
    if user_input == 'Q':
        break

##Exercise 2
for i in range(1, 51):
    if i % 3 == 0:
        continue
    print(i)
