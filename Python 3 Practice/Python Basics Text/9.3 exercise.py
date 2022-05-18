##9.3
##Exercise 1
data = ((1, 2), (3, 4))
print(data)

##Exercise 2
for i in range(len(data)):
    print(f'Row {i+1} sum: {sum(data[i])}')

##Exercise 3
numbers = [4, 3, 2, 1]
print(numbers)

##Exercise 4
numerical_order = numbers[:]
print(numbers)
print(numerical_order)

##Exercise 5
numerical_order.sort()
print(numerical_order)
print(numbers)
