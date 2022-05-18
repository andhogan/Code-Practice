# create the initial variables below
age = 28
sex = 0
bmi = 26.2
num_of_children = 3
smoker = 0

# Add insurance estimate formula below
insurance_costs = (250 * age) - (128 * sex) + (370 * bmi) + (425 * num_of_children) + (24000 * smoker) - 12500

print(f'This person\'s insurance cost is {insurance_costs} dollars.')
print("This person's insurance cost is " 
+ str(insurance_costs) + " dollars.")

# Age Factor
age += 4
new_insurance_costs = (250 * age) - (128 * sex) + (370 * bmi) + (425 * num_of_children) + (24000 * smoker) - 12500
change_in_insurance_costs = new_insurance_costs - insurance_costs

print(f'The change in cost of insurance after increasing the age by 4 years is {change_in_insurance_costs} dollars.')

# BMI Factor
age -= 4
bmi += 3.1
new_insurance_costs = (250 * age) - (128 * sex) + (370 * bmi) + (425 * num_of_children) + (24000 * smoker) - 12500
change_in_insurance_costs = new_insurance_costs - insurance_costs

print(f'The change in cost of insurance after increasing BMI by 3.1 is {change_in_insurance_costs} dollars.')

# Male vs. Female Factor
bmi -= 3.1
sex = 1
new_insurance_costs = (250 * age) - (128 * sex) + (370 * bmi) + (425 * num_of_children) + (24000 * smoker) - 12500
change_in_insurance_costs = new_insurance_costs - insurance_costs

print(f'The change in cost of insurance for being male instead of female is {change_in_insurance_costs} dollars.')

# Extra Practice
sex = 0
smoker = 1
new_insurance_costs = (250 * age) - (128 * sex) + (370 * bmi) + (425 * num_of_children) + (24000 * smoker) - 12500
change_in_insurance_costs = new_insurance_costs - insurance_costs

print(f'The change in cost of insurance for being a smoker is {change_in_insurance_costs} dollars.')