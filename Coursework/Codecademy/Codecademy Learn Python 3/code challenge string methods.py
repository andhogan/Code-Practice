def unique_english_letters(word):
    unique_english_characters_list = []
    for i in range(len(word)):
        if word[i] not in unique_english_characters_list:
            unique_english_characters_list.append(word[i])
    return len(unique_english_characters_list)

# Uncomment these function calls to test your function:
print(unique_english_letters("mississippi"))
# should print 4
print(unique_english_letters("Apple"))
# should print 4

#--------------------------------

# Write your count_char_x function here:
def count_char_x(word, x):
  counter = 0
  for i in word:
    if i == x:
      counter += 1
  return counter

# Uncomment these function calls to test your tip function:
print(count_char_x("mississippi", "s"))
# should print 4
print(count_char_x("mississippi", "m"))
# should print 1

#--------------------------------

# Write your count_multi_char_x function here:
def count_multi_char_x(word, x):
  multi_frag_list = (word.split(x))
  return len(multi_frag_list) - 1

# Uncomment these function calls to test your function:
print(count_multi_char_x("mississippi", "iss"))
# should print 2
print(count_multi_char_x("apple", "pp"))
# should print 1

#---------------------------------

def reverse_string(word):
  return word[::-1]

# Uncomment these function calls to test your  function:
print(reverse_string("Codecademy"))
# should print ymedacedoC
print(reverse_string("Hello world!"))
# should print !dlrow olleH
print(reverse_string(""))
# should print
#--------------------------------

