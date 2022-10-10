#Ques link - https://www.hackerrank.com/contests/int213-contest25/challenges/basic-probability-puzzles-5

from fractions import Fraction

places = [i for i in range(0, 10, 1)]
total = 0
visited = []

for e, i in enumerate(places):
    for j in places[0:e] + places[e+1:]:
        if i == 0:
            if j == 9:
                visited.append([i, j])
            elif j == 1:
                visited.append([i, j])
        elif i == 9:
            if j == 0:
                visited.append([i, j])
            elif j == 8:
                visited.append([i, j])
        else:
            if (i == (j - 1)) or (i == (j + 1)):
                visited.append([i, j])
        
        total += 1

print(Fraction(len(visited), total))