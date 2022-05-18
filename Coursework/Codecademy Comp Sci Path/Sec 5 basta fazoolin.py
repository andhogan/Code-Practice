import datetime

class Menu:
  def __init__(self, name, items, start_time, end_time):
    self.name = name
    self.items = items
    self.start_time = start_time
    self.end_time = end_time

  def __repr__(self):
      return """
      This is the {} menu, served between the hours of 
      {} and {} daily.
      """.format(self.name, self.start_time, self.end_time)

  def calculate_bill(self, purchased_items):
    bill = 0
    for item in purchased_items:
      if item in self.items:
        bill += self.items[item]
    return bill
    
brunch = Menu("Brunch", 
{
    'pancakes': 7.50, 
    'waffles': 9.00, 
    'burger': 11.00, 
    'home fries': 4.50, 
    'coffee': 1.50, 
    'espresso': 3.00, 
    'tea': 1.00, 
    'mimosa': 10.50, 
    'orange juice': 3.50
} , 
start_time=datetime.time(11,0,0,0), 
end_time=datetime.time(16,0,0,0))

early_bird = Menu("Early Bird",
{
  'salumeria plate': 8.00, 
  'salad and breadsticks (serves 2, no refills)': 14.00, 
  'pizza with quattro formaggi': 9.00, 
  'duck ragu': 17.50, 
  'mushroom ravioli (vegan)': 13.50, 
  'coffee': 1.50, 
  'espresso': 3.00,
},
start_time=datetime.time(15,0,0,0),
end_time=datetime.time(18,0,0,0))

dinner = Menu("Dinner",
{
  'crostini with eggplant caponata': 13.00, 
  'ceaser salad': 16.00, 
  'pizza with quattro formaggi': 11.00, 
  'duck ragu': 19.50, 
  'mushroom ravioli (vegan)': 13.50, 
  'coffee': 2.00, 
  'espresso': 3.00,
},
start_time=datetime.time(17,0,0,0),
end_time=datetime.time(23,0,0,0))

kids = Menu("Kids",
{
  'chicken nuggets': 6.50, 
  'fusilli with wild mushrooms': 12.00, 
  'apple juice': 3.00
}, 
start_time=datetime.time(11,0,0,0), 
end_time=datetime.time(21,0,0,0))

print(brunch)
print(early_bird)
print(dinner)
print(kids)

print(brunch.calculate_bill(['pancakes', 'home fries', 'coffee']))
print(early_bird.calculate_bill(['salumeria plate', 'mushroom ravioli (vegan)']))

class Franchise:
  def __init__(self, address, menu_list):
    self.address = address
    self.menu_list = menu_list
  def __repr__(self):
    return """This franchise is located at {}.
    """.format(self.address)

  def available_menus(self, time):
    #available_list = [menu for menu in self.menus if menu.start_time <= time <+ menu.end_time]
    available_list = []
    for menu in self.menu_list:
        if menu.start_time <= time <= menu.end_time:
            available_list.append(menu)
    return available_list
    
flagship_store = Franchise("1232 West End Road", 
[kids, brunch, early_bird, dinner])
new_installment = Franchise("12 East Mukberry Street", 
[kids, brunch, early_bird, dinner])

print(flagship_store.available_menus(time=datetime.time(12)))
print(new_installment.available_menus(time=datetime.time(12)))
print(flagship_store.available_menus(time=datetime.time(17)))
print(new_installment.available_menus(time=datetime.time(17)))

class Business:
    def __init__(self, name, franchise_list):
        self.name = name
        self.franchise_list = franchise_list

basta = Business("Basta Fazoolin' with my Heart", [flagship_store, new_installment])
arepas_menu = Menu("Take a' Arepa", {
  'arepa pabellon': 7.00, 
  'pernil arepa': 8.50, 
  'guayanes arepa': 8.00, 
  'jamon arepa': 7.50
}, start_time=datetime.time(10),
end_time=datetime.time(20))

arepas_place = Franchise("189 Fitzgerald Avenue", [arepas_menu])
arepas = Business("Take a' Arepa", [new_installment, flagship_store])