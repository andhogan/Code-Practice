#Exercise 1
category='Animals'
mammal='Badger'
insect='Honey Bee'
mammal1='Honeybadger'

print(category.lower())
print(mammal.lower())
print(insect.lower())
print(mammal1.lower())

#Exercise 2
category='Animals'
mammal='Badger'
insect='Honey Bee'
mammal1='Honeybadger'

print(category.upper())
print(mammal.upper())
print(insect.upper())
print(mammal1.upper())

#Exercise 3
meal1='     Filet Mignon'
meal2='Brisket     '
meal3='     Cheeseburger     '

print(meal1.lstrip())
print(meal2.rstrip())
print(meal3.strip())

#Exercise 4
string1='Becomes'
string2='becomes'
string3='BEAR'
string4=' bEautiful'

print(string1.startswith('be'))
print(string2.startswith('be'))
print(string3.startswith('be'))
print(string4.startswith('be'))

#Exercise 5
print(string1.lower().startswith('be'))
print(string2.startswith('be'))
print(string3.lower().startswith('be'))
print(string4.lstrip().lower().startswith('be'))
