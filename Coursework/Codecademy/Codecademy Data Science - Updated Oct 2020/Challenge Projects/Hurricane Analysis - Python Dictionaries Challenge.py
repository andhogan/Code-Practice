# names of hurricanes
names = ['Cuba I', 'San Felipe II Okeechobee', 'Bahamas', 'Cuba II', 'CubaBrownsville', 'Tampico', 'Labor Day', 'New England', 'Carol', 'Janet', 'Carla', 'Hattie', 'Beulah', 'Camille', 'Edith', 'Anita', 'David', 'Allen', 'Gilbert', 'Hugo', 'Andrew', 'Mitch', 'Isabel', 'Ivan', 'Emily', 'Katrina', 'Rita', 'Wilma', 'Dean', 'Felix', 'Matthew', 'Irma', 'Maria', 'Michael']

# months of hurricanes
months = ['October', 'September', 'September', 'November', 'August', 'September', 'September', 'September', 'September', 'September', 'September', 'October', 'September', 'August', 'September', 'September', 'August', 'August', 'September', 'September', 'August', 'October', 'September', 'September', 'July', 'August', 'September', 'October', 'August', 'September', 'October', 'September', 'September', 'October']

# years of hurricanes
years = [1924, 1928, 1932, 1932, 1933, 1933, 1935, 1938, 1953, 1955, 1961, 1961, 1967, 1969, 1971, 1977, 1979, 1980, 1988, 1989, 1992, 1998, 2003, 2004, 2005, 2005, 2005, 2005, 2007, 2007, 2016, 2017, 2017, 2018]

# maximum sustained winds (mph) of hurricanes
max_sustained_winds = [165, 160, 160, 175, 160, 160, 185, 160, 160, 175, 175, 160, 160, 175, 160, 175, 175, 190, 185, 160, 175, 180, 165, 165, 160, 175, 180, 185, 175, 175, 165, 180, 175, 160]

# areas affected by each hurricane
areas_affected = [['Central America', 'Mexico', 'Cuba', 'Florida', 'The Bahamas'], ['Lesser Antilles', 'The Bahamas', 'United States East Coast', 'Atlantic Canada'], ['The Bahamas', 'Northeastern United States'], ['Lesser Antilles', 'Jamaica', 'Cayman Islands', 'Cuba', 'The Bahamas', 'Bermuda'], ['The Bahamas', 'Cuba', 'Florida', 'Texas', 'Tamaulipas'], ['Jamaica', 'Yucatn Peninsula'], ['The Bahamas', 'Florida', 'Georgia', 'The Carolinas', 'Virginia'], ['Southeastern United States', 'Northeastern United States', 'Southwestern Quebec'], ['Bermuda', 'New England', 'Atlantic Canada'], ['Lesser Antilles', 'Central America'], ['Texas', 'Louisiana', 'Midwestern United States'], ['Central America'], ['The Caribbean', 'Mexico', 'Texas'], ['Cuba', 'United States Gulf Coast'], ['The Caribbean', 'Central America', 'Mexico', 'United States Gulf Coast'], ['Mexico'], ['The Caribbean', 'United States East coast'], ['The Caribbean', 'Yucatn Peninsula', 'Mexico', 'South Texas'], ['Jamaica', 'Venezuela', 'Central America', 'Hispaniola', 'Mexico'], ['The Caribbean', 'United States East Coast'], ['The Bahamas', 'Florida', 'United States Gulf Coast'], ['Central America', 'Yucatn Peninsula', 'South Florida'], ['Greater Antilles', 'Bahamas', 'Eastern United States', 'Ontario'], ['The Caribbean', 'Venezuela', 'United States Gulf Coast'], ['Windward Islands', 'Jamaica', 'Mexico', 'Texas'], ['Bahamas', 'United States Gulf Coast'], ['Cuba', 'United States Gulf Coast'], ['Greater Antilles', 'Central America', 'Florida'], ['The Caribbean', 'Central America'], ['Nicaragua', 'Honduras'], ['Antilles', 'Venezuela', 'Colombia', 'United States East Coast', 'Atlantic Canada'], ['Cape Verde', 'The Caribbean', 'British Virgin Islands', 'U.S. Virgin Islands', 'Cuba', 'Florida'], ['Lesser Antilles', 'Virgin Islands', 'Puerto Rico', 'Dominican Republic', 'Turks and Caicos Islands'], ['Central America', 'United States Gulf Coast (especially Florida Panhandle)']]

# damages (USD($)) of hurricanes
damages = ['Damages not recorded', '100M', 'Damages not recorded', '40M', '27.9M', '5M', 'Damages not recorded', '306M', '2M', '65.8M', '326M', '60.3M', '208M', '1.42B', '25.4M', 'Damages not recorded', '1.54B', '1.24B', '7.1B', '10B', '26.5B', '6.2B', '5.37B', '23.3B', '1.01B', '125B', '12B', '29.4B', '1.76B', '720M', '15.1B', '64.8B', '91.6B', '25.1B']

# deaths for each hurricane
deaths = [90,4000,16,3103,179,184,408,682,5,1023,43,319,688,259,37,11,2068,269,318,107,65,19325,51,124,17,1836,125,87,45,133,603,138,3057,74]

##########################################
# write your update damages function here:
def update_damages(damages_list):
  conversion = {"M": 1000000, 
                "B": 1000000000}
  new_damages_list = []
  for damages in damages_list:
    if damages.endswith("M"):
      format_damage = damages.strip("M")
      float_damage = float(format_damage)
      converted_damage = float_damage * conversion["M"]
      new_damages_list.append(converted_damage)
    elif damages.endswith("B"):
      format_damage = damages.strip("B")
      float_damage = float(format_damage)
      converted_damage = float_damage * conversion["B"]
      new_damages_list.append(converted_damage)
    else:
      new_damages_list.append(damages)
  return new_damages_list

updated_damages_list = update_damages(damages)
#print(updated_damages_list)





##########################################################
# write your construct hurricane dictionary function here:
def construct_hurricane_dictionary(names, months, years, 
max_sustained_winds, areas_affected, damages, deaths):
  hurricane_dictionary = {}
  for index in range(len(names)):
    hurricane_dictionary.update(
      {names[index]: 
        {"Name": names[index],
        "Month": months[index],
        "Year": years[index],
        "Max Sustained Wind": max_sustained_winds[index],
        "Areas Affected": areas_affected[index],
        "Damage": damages[index],
        "Deaths": deaths[index]}})
  return hurricane_dictionary

hurricanes = construct_hurricane_dictionary(names, months, years, 
max_sustained_winds, areas_affected, updated_damages_list, deaths)
#print(hurricanes)






##################################################################
# write your construct hurricane by year dictionary function here:
def yearly_hurricane_dict_construct(hurricane_dict):
  yearly_hurricane_dict = {}
  for hurr_info in hurricane_dict:
    current_year = hurricane_dict[hurr_info]['Year']
    current_cane = hurricane_dict[hurr_info]
    if current_year not in yearly_hurricane_dict.keys():
      yearly_hurricane_dict[current_year] = [current_cane]
    else:
      yearly_hurricane_dict[current_year].append(current_cane)
  return yearly_hurricane_dict

yearly_hurricane_dict = yearly_hurricane_dict_construct(hurricanes)

#print(yearly_hurricane_dict)
#print(yearly_hurricane_dict.keys())
#print(len(yearly_hurricane_dict.keys()))
#print(len(yearly_hurricane_dict.values()))
#print(len(years))


################################################
# write your count affected areas function here:
def count_affected_hurr_areas(hurricane_dict):
  affected_hurr_areas_dict = {}
  for hurr_info in hurricane_dict:
    current_area = hurricane_dict[hurr_info]['Areas Affected']
    for area in current_area:
      if area not in affected_hurr_areas_dict.keys():
        affected_hurr_areas_dict[area] = 1
      else:
        affected_hurr_areas_dict[area] += 1
  return affected_hurr_areas_dict

affected_hurr_areas = count_affected_hurr_areas(hurricanes)
#print(affected_hurr_areas)





###################################################
# write your find most affected area function here:
def most_affected_area(affected_hurr_areas_dict):
  max_area = ''
  max_area_count = 0
  for key, value in affected_hurr_areas_dict.items():
    if value > max_area_count:
      max_area_count = value
      max_area = key
  return max_area, max_area_count

#print(most_affected_area(affected_hurr_areas))




#####################################################
# write your greatest number of deaths function here:
def most_deaths(hurricane_dict):
  deadliest_hurricane = ''
  max_mortality = 0
  for hurr_info in hurricane_dict:
    current_death = hurricane_dict[hurr_info]['Deaths']
    if current_death > max_mortality:
      max_mortality = current_death
      deadliest_hurricane = hurricane_dict[hurr_info]['Name']
  return deadliest_hurricane, max_mortality

#print(most_deaths(hurricanes))



###################################################
# write your catgeorize by mortality function here:
def categorize_by_mortality(hurricane_dict):
  mortality_dict = {0: [], 
                    1: [], 
                    2: [], 
                    3: [], 
                    4: [], 
                    5: []}
  mortality_scale = {0: 0,
                     1: 100,
                     2: 500,
                     3: 1000,
                     4: 10000}
  for hurr_info in hurricane_dict:
    current_mortality = hurricane_dict[hurr_info]['Deaths']
    if current_mortality > mortality_scale[4]:
      mortality_dict[5].append(hurricane_dict[hurr_info])
    elif mortality_scale[3] < current_mortality <= mortality_scale[4]:
      mortality_dict[4].append(hurricane_dict[hurr_info])
    elif mortality_scale[2] < current_mortality <= mortality_scale[3]:
      mortality_dict[3].append(hurricane_dict[hurr_info])
    elif mortality_scale[1] < current_mortality <= mortality_scale[2]:
      mortality_dict[2].append(hurricane_dict[hurr_info])
    elif mortality_scale[0] < current_mortality <= mortality_scale[1]:
      mortality_dict[1].append(hurricane_dict[hurr_info])
    else:
      mortality_dict[0].append(hurricane_dict[hurr_info])
  
  return mortality_dict

#print(categorize_by_mortality(hurricanes))



###########################################
# write your greatest damage function here:

def most_damage(hurricane_dict):
  destructive_hurricane = ''
  max_damage = 0
  for hurr_info in hurricane_dict:
    current_damage = hurricane_dict[hurr_info]['Damage']
    try:
      if current_damage > max_damage:
        max_damage = current_damage
        destructive_hurricane = hurricane_dict[hurr_info]['Name']
    except TypeError:
      continue
  return destructive_hurricane, max_damage

#print(most_damage(hurricanes))




################################################
# write your categorize by damage function here:

def categorize_by_damage(hurricane_dict):
  damage_dict ={0: [], 
                1: [], 
                2: [], 
                3: [], 
                4: [], 
                5: [],
                'No Damage Data': []}
  damage_scale = {0: 0,
                  1: 100000000,
                  2: 1000000000,
                  3: 10000000000,
                  4: 50000000000}
  for hurr_info in hurricane_dict:
    current_damage = hurricane_dict[hurr_info]['Damage']
    try:
      if current_damage > damage_scale[4]:
        damage_dict[5].append(hurricane_dict[hurr_info])
      elif damage_scale[3] < current_damage <= damage_scale[4]:
        damage_dict[4].append(hurricane_dict[hurr_info])
      elif damage_scale[2] < current_damage <= damage_scale[3]:
        damage_dict[3].append(hurricane_dict[hurr_info])
      elif damage_scale[1] < current_damage <= damage_scale[2]:
        damage_dict[2].append(hurricane_dict[hurr_info])
      elif damage_scale[0] < current_damage <= damage_scale[1]:
        damage_dict[1].append(hurricane_dict[hurr_info])
      else:
        damage_dict[0].append(hurricane_dict[hurr_info])
    except TypeError:
      damage_dict['No Damage Data'].append(hurricane_dict[hurr_info])
  
  return damage_dict


print(categorize_by_damage(hurricanes))

