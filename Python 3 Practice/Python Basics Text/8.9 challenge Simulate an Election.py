import random

def election_region(prob_A_win):
    if random.random() < prob_A_win:
        return "A"
    else:
        return "B"

A_tally = 0
B_tally = 0
A_win = 0
B_win = 0
for i in range (10000):
    if election_region(.87) == "A":
        A_tally = A_tally + 1
    else:
        B_tally = B_tally + 1

    if election_region(.65) == "A":
        A_tally = A_tally + 1
    else:
        B_tally = B_tally + 1

    if election_region(.17) == "A":
        A_tally = A_tally + 1
    else:
        B_tally = B_tally + 1

    if A_tally >= 2:
        A_win = A_win + 1
        A_tally = 0
        B_tally = 0
    else:
        B_win = B_win + 1
        A_tally = 0
        B_tally = 0

if A_win > B_win:
    print(f"Candidate A has a chance of winning by \
{A_win/10000:.2%}")
else:
    print(f"Candidate B wins the election with {B_win} \
wins over Candidate A's {A_win} wins.")
