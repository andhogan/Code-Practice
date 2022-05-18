medical_data = \
"""Marina Allison   ,27   ,   31.1 , 
#7010.0   ;Markus Valdez   ,   30, 
22.4,   #4050.0 ;Connie Ballard ,43 
,   25.3 , #12060.0 ;Darnell Weber   
,   35   , 20.6   , #7500.0;
Sylvie Charles   ,22, 22.1 
,#3022.0   ;   Vinay Padilla,24,   
26.9 ,#4620.0 ;Meredith Santiago, 51   , 
29.3 ,#16330.0;   Andre Mccarty, 
19,22.7 , #2900.0 ; 
Lorena Hodson ,65, 33.1 , #19370.0; 
Isaac Vu ,34, 24.8,   #7045.0"""

# Add your code here
#print(medical_data)
updated_medical_data = medical_data.replace('#', '$')
print(updated_medical_data)
print()

num_records = 0
for sign in updated_medical_data:
  if sign == '$':
    num_records += 1
print('There are {} medical records in the data.'.format(num_records))
print()


##   Splitting Strings   ##
medical_data_split = updated_medical_data.split(';')
#print(medical_data_split)

medical_records = []
for record in medical_data_split:
  medical_records.append(record.split(','))
#print(medical_records)


##   Cleaning Data   ##
medical_records_clean = []
for record in medical_records:
  record_clean = []
  for item in record:
    record_clean.append(item.strip())
  medical_records_clean.append(record_clean)
print(medical_records_clean)
print()

##   Analyzing Data   ##
for record in medical_records_clean:
  record[0] = record[0].upper()
  print(record[0])

names = []
ages = []
bmis = []
insurance_costs = []

for record in medical_records_clean:
  names.append(record[0])
  ages.append(record[1])
  bmis.append(record[2])
  insurance_costs.append(record[3])

print("Names: " + str(names))
print("Ages: " + str(ages))
print("BMIs: " + str(bmis))
print("Insurance Costs: " + str(insurance_costs))

total_bmi = 0
for bmi in bmis:
  total_bmi += float(bmi)
average_bmi = total_bmi / len(bmis)
print(f"Average BMI: {average_bmi:.2f}")

## EXTRA ##
float_insurance_costs = []
for cost in insurance_costs:
  float_cost = cost.lstrip('$')
  float_insurance_costs.append(float(float_cost))

total_insurance_costs = 0
for cost in float_insurance_costs:
  total_insurance_costs += cost
average_insurance_costs = total_insurance_costs / len(float_insurance_costs)

print(f'Average Insurance Costs: ${average_insurance_costs:.2f}')

recombined_medical_records = list(zip(names, ages, bmis, float_insurance_costs))

for record in recombined_medical_records:
  print(f'\n{record[0]} is {record[1]} years old with a BMI of {record[2]} and an insurance cost of ${record[3]:.2f}.')