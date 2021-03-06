# Write your sum_values function here:
def sum_values(my_dictionary):
  counter = 0
  for value in my_dictionary.values():
    counter += value
  return counter
# Uncomment these function calls to test your sum_values function:
print(sum_values({"milk":5, "eggs":2, "flour": 3}))
# should print 10
print(sum_values({10:1, 100:2, 1000:3}))
# should print 6

#---------------------------------------

# Write your sum_even_keys function here:
def sum_even_keys(my_dictionary):
  counter = 0
  for even in my_dictionary.keys():
    if even % 2 == 0:
      counter += my_dictionary.get(even)
  return counter
# Uncomment these function calls to test your  function:
print(sum_even_keys({1:5, 2:2, 3:3}))
# should print 2
print(sum_even_keys({10:1, 100:2, 1000:3}))
# should print 6

#---------------------------------------

# Write your add_ten function here:
def add_ten(my_dictionary):
  for item in my_dictionary.items():
    key = item[0]
    value = item[1]
    my_dictionary[key] = value + 10
  return my_dictionary
# Uncomment these function calls to test your  function:
print(add_ten({1:5, 2:2, 3:3}))
# should print {1:15, 2:12, 3:13}
print(add_ten({10:1, 100:2, 1000:3}))
# should print {10:11, 100:12, 1000:13}

#---------------------------------------

# Write your values_that_are_keys function here:
def values_that_are_keys(my_dictionary):
  new_list = []
  for value in my_dictionary.values():
    if value in my_dictionary.keys():
      new_list.append(value)
  return new_list
# Uncomment these function calls to test your  function:
print(values_that_are_keys({1:100, 2:1, 3:4, 4:10}))
# should print [1, 4]
print(values_that_are_keys({"a":"apple", "b":"a", "c":100}))
# should print ["a"]

#---------------------------------------

