##Exercise 1
for n in range(2, 11):
    print(n)

##Exercise 2
j = 2
while j <11:
    print(j)
    j = j+1

##Exercise 3
def doubles(x):
    """Multiplies a number by 2"""
    y = x * 2
    return y

num = 2
for i in range (0,5):
    num = doubles(num)
    print(num)
