# Add your code here
medical_costs = {}
medical_costs['Marina'] = 6607.0
medical_costs['Vinay'] = 3225.0
medical_costs.update({"Connie": 8886.0, "Isaac": 16444.0, "Valentina": 6420.0})
medical_costs['Vinay'] = 3325.0
#print(medical_costs)

total_cost = 0
for cost in medical_costs.values():
  total_cost += cost
#print(f'Total Cost: ${total_cost:.2f}')
average_cost = total_cost / len(medical_costs)
#print(f'Average Cost: ${average_cost:.2f}')

##   List Comprehension to Dictionary   ##
names = ['Marina', 'Vinay', 'Connie', 'Isaac', 'Valentina']
ages = [27, 24, 43, 35, 52]
zipped_lists = zip(names, ages)
names_to_ages = {key:value for key, value in zipped_lists}
#print(names_to_ages)

marina_age = names_to_ages.get('Marina', None)
#print(f'Marina\'s age is {marina_age}.')


##   Using a Dictionary to create a medical database   ##
medical_records = {}
medical_records['Marina'] = {"Age": 27, "Sex": "Female", "BMI": 31.1, "Children": 2, "Smoker": "Non-smoker", "Insurance Cost": 6607.0}

medical_records.update({'Vinay': {"Age": 24, "Sex": "Male", "BMI": 26.9, "Children": 2, "Smoker": "Non-smoker", "Insurance Cost": 3225.0}, 'Connie': {"Age": 43, "Sex": "Female", "BMI": 25.3, "Children": 3, "Smoker": "Non-smoker", "Insurance Cost": 8886.0}, 'Isaac': {"Age": 35, "Sex": "Male", "BMI": 20.6, "Children": 4, "Smoker": "Smoker", "Insurance Cost": 16444.0}, 'Valentina': {"Age": 52, "Sex": "Female", "BMI": 18.7, "Children": 1, "Smoker": "Non-smoker", "Insurance Cost": 6420.0}})

#print(medical_records)
#print()
#print('Connie\'s insurance cost is {} dollars.'.format(medical_records['Connie']['Insurance Cost']))
#print()

medical_records.pop('Vinay')

##   EXTRA   ##
def update_medical_records(patient_name, patient_medical_dictionary):
  medical_records.update({patient_name: patient_medical_dictionary})

update_medical_records('Andrew', {"Age": 25, "Sex": "Male", "Smoker": "Non-smoker", "BMI": 18.5, "Insurance Cost": 2550.0})

print(medical_records)
print()
for key, value in medical_records.items():
  print(f'{key} is a {value["Age"]} year old {value["Sex"]} {value["Smoker"]} with a BMI of {value["BMI"]} and insurance cost of {value["Insurance Cost"]} dollars.')