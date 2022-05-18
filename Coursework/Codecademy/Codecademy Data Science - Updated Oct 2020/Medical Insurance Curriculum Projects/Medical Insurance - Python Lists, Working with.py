names = ["Mohamed", "Sara", "Xia", "Paul", "Valentina", "Jide", "Aaron", "Emily", "Nikita", "Paul"]
insurance_costs = [13262.0, 4816.0, 6839.0, 5054.0, 14724.0, 5360.0, 7640.0, 6072.0, 2750.0, 12064.0]

# Add your code here
names.append("Priscilla")
insurance_costs.append(8320.0)
medical_records = list(zip(insurance_costs, names))
print(medical_records)
print()

num_medical_records = len(medical_records)
print("There are {0} medical records.".format(num_medical_records))
print()

first_medical_record = medical_records[0]
print("Here is the first medical record:\n {0}".format(first_medical_record))
print()

medical_records.sort()
print("Here are the medical records sorted by insurance cost:")
print(medical_records)
print()

cheapest_three = medical_records[0:3]
print("Here are the three cheapest insurance costs in our medical records:")
for record in cheapest_three:
  print(record)
print()

expensive_three = medical_records[-3:]
print("Here are the three cheapest insurance costs in our medical records:")
for record in expensive_three:
  print(record)
print()

occurrences_paul = names.count('Paul')
print("There are {0} individuals with the name Paul in our medical records.".format(occurrences_paul))