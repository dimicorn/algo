from dataclasses import dataclass


@dataclass
class Candidate:
    party : str
    votes : int = 0


n = int(input())

cands = dict()
for i in range(n):
    name = input()
    party = input()
    c = Candidate(party)
    cands[name] = c

m = int(input())

for i in range(m):
    name = input()
    if name in cands:
        cands[name].votes += 1

max_votes = 0
max_party = "n/a"


for i in cands:
    tmp = cands[i]
    if tmp.votes > max_votes:
        max_votes = tmp.votes
        max_party = tmp.party
    elif tmp.votes == max_votes:
        max_party = "tie"

print(max_party)