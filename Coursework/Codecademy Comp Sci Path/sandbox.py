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