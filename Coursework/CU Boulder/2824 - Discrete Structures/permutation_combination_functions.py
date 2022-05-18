from math import factorial

def permutation(n, k):

    return int(factorial(n)/factorial(n-k))

def combination(n, k):

    return int(permutation(n, k) / factorial(k))

#print(factorial(4))
#print(factorial(7))

from math import pow, factorial
# note pow(x, i) calculates x^i
#      factorial(j) calculates j!
def combination(n, j):
    return factorial(n)/(factorial(n-j)*factorial(j))
    
def binom_product(a, b, n):
    product = 1
    for j in range(0, n+1):
        product *= combination(n, j) * pow(a, n-j) * pow(b, j)
    
    return product

print(1-(combination(48, 5)/combination(52, 5)))