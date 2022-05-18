def invest(amount, rate, years):
    """Calculates principal amount after annual \
rate of return applied over an input amount of years."""
    for year in range (1, years+1):
        amount = amount * (1 + rate)
        print(f"year {year}: ${amount:,.2f}")

amount = float(input("Enter principal amount: "))
rate = float(input("Enter annual rate of return: "))
years = int(input("Enter number of years: "))

invest(amount, rate, years)
