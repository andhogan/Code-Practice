grocery_list = ['milk', 'eggs', 'bananas', 'cereal', 'yogurt', 'bacon', 'orange juice'] 
# list to iterate
cart = []
# empty list

while grocery_list: # iterate as long as there are items in the grocery list
    for item in grocery_list:
        # Ask the user whether the item has been found and to insert into the cart
        print('Grocery List: {}'.format(grocery_list)) # shows the current grocery list.
        print('Cart: {}'.format(cart)) # shows items in the cart
        print()
        user_input = str(input("Insert this item into cart: {} ? Y/N     ".format(item))) 
        if user_input.lower() == 'y': # checks user's input
            cart.append(item) # appends the found item to the cart list
            grocery_list.remove(item) # removes item from grocery list
        else:
            continue # continue with the loop if the item has not been found.

# If this message prints, the grocery list is empty
print("All of your items are in your cart! Happy shopping!") 