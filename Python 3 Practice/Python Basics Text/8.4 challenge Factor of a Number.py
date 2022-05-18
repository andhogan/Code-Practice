pos_int = int(input('Enter a positive integer: '))

for i in range(1, (pos_int + 1)):
    if ((pos_int) % (i)) == 0:
        print(f'{i} is a factor of {pos_int}')
