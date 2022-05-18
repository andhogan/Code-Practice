def CelToFar(C):
    """Converts degrees Celsius to degrees Fahrenheit."""
    F = (C * 9/5) + 32
    return F

def FarToCel(F):
    """Converts degrees Fahrenheit to degrees Celsius."""
    C = (F - 32) * 5/9
    return C

F = input("Enter a temperature in degrees F: ")

C = FarToCel(float(F))

print(f'{F} degrees F = {round(C, 2)} degrees C.')

C = input("Enter a temperature in degrees C: ")

F = CelToFar(float(C))

print (f'{C} degrees C = {F:.2f} degrees F.')
