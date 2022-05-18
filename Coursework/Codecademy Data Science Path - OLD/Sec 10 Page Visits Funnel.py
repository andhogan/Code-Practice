import pandas as pd

visits = pd.read_csv('visits.csv',
                     parse_dates=[1])
cart = pd.read_csv('cart.csv',
                   parse_dates=[1])
checkout = pd.read_csv('checkout.csv',
                       parse_dates=[1])
purchase = pd.read_csv('purchase.csv',
                       parse_dates=[1])
"""print(visits.head())
print(cart.head())
print(checkout.head())
print(purchase.head())"""

visits_cart = pd.merge(visits, cart, how='left')
visits_cart_length = len(visits_cart)
print(visits_cart_length)

null_rows_count = len(visits_cart[visits_cart.cart_time.isnull()])
print(null_rows_count)

visits_cart_null_percent = null_rows_count / float(visits_cart_length)
print(visits_cart_null_percent)

#######################

cart_checkout = pd.merge(cart, checkout, how='left')
#print(cart_checkout)
cart_checkout_length = len(cart_checkout)
print(cart_checkout_length)

null_rows_cart_checkout_count = len(cart_checkout[cart_checkout.checkout_time.isnull()])
print(null_rows_cart_checkout_count)

cart_checkout_null_percent = null_rows_cart_checkout_count / float(cart_checkout_length)
print(cart_checkout_null_percent)
###########################

checkout_purchase = pd.merge(checkout, purchase, how='left')
checkout_purchase_rows = len(checkout_purchase)
purchase_null_count = len(checkout_purchase[checkout_purchase.purchase_time.isnull()])
#print(checkout_purchase_rows)
#print(purchase_null_count)
checkout_purchase_null_percent = float(purchase_null_count) / checkout_purchase_rows
#print(checkout_purchase_null_percent)
print('\n')

print('Visit/Cart funnel: {}'.format(visits_cart_null_percent))
print('Cart/Checkout funnel: {}'.format(cart_checkout_null_percent))
print("Checkout/Purchase funnel: {}".format(checkout_purchase_null_percent))

###############################

all_data = pd.merge(visits, cart, how='left').merge(checkout, how='left').merge(purchase, how='left')
all_data['time_to_purchase'] = \
    all_data.purchase_time - \
    all_data.visit_time
#print(all_data)
print(all_data.time_to_purchase)
print(all_data.time_to_purchase.mean())