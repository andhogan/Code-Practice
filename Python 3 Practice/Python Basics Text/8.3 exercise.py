word = str(input("Enter a word: "))

word = word.upper()

if len(word) > 5:
    print(f'{word} has a length of {len(word)}, and is greater than 5 characters.')

elif len(word) < 5:
    print(f'{word} has a length of {len(word)}, and is less than 5 characters.')

else:
    print(f'{word} has a length of {len(word)}, and is equal in length to 5 characters.')
    
