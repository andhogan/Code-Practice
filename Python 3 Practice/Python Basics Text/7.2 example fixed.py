def add_underscores(word):
    new_word = "_"
    for char in word:
        new_word = new_word + char + "_"
    return new_word


##def add_underscores(word):
##    new_word = "_"
##    for i in range(0, len(word)):
##        new_word = new_word word[i] + "_"
##        print(f"i = {i}; new_word = {new_word}")
##    return new_word
##
phrase = "hello"
print(add_underscores(phrase))
