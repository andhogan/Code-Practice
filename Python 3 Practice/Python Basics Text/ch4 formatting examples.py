string1='420'
print(float(string1)*3)
integer1=float(string1)
print(string1 + ' ' + str(integer1))

user_input1=int(input("Input first number here:"))
user_input2=int(input("Input second number here:"))
output=float(user_input1*user_input2)
print("The product of " + str(user_input1) + " and " + str(user_input2) + ' is ' + str(output))
print('The product of', str(user_input1), "and", str(user_input2), "is", str(output))
print(f'The product of {user_input1} and {user_input2} is {output}')
