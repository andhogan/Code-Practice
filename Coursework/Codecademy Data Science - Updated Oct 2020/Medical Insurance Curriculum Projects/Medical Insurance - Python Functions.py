# Create calculate_insurance_cost() function below:
def calculate_insurance_cost(age, sex, bmi, num_of_children, smoker, name="this person"):
  estimated_cost = 250*age - 128*sex + 370*bmi + 425*num_of_children + 24000*smoker - 12500
  print(f'The estimated insurance cost for {name} is {estimated_cost} dollars.')
  #print('The estimated insurance cost for {0} is {1} dollars.'.format(name, estimated_cost))
  return estimated_cost

# Initial variables for Maria 
#age = 28
#sex = 0  
#bmi = 26.2
#num_of_children = 3
#smoker = 0  

# Estimate Maria's insurance cost
maria_insurance_cost = calculate_insurance_cost(age=28, sex=0, bmi=26.2, num_of_children=3, smoker=0, name="Maria")
#print("The estimated insurance cost for Maria is " + str(maria_insurance_cost) + " dollars.")

# Initial variables for Omar
#age = 35
#sex = 1 
#bmi = 22.2
#num_of_children = 0
#smoker = 1  

# Estimate Omar's insurance cost 
omar_insurance_cost = calculate_insurance_cost(age=35, sex=1, bmi=22.2, num_of_children=0, smoker=1, name="Omar")

#print("The estimated insurance cost for Omar is " + str(omar_insurance_cost) + " dollars.")

# Estimate my insurance cost
my_insurance_cost = calculate_insurance_cost(age=25, sex=1, bmi=20.0, num_of_children=0, smoker=0, name="Andrew")