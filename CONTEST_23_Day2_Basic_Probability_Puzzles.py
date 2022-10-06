#ques limk -  https://www.hackerrank.com/contests/int213-contest23/challenges/basic-probability-puzzles-1/problem

from fractions import Fraction

def main():
    total_combo = 6*6
    count = 0

    for i in range(1, 7, 1):
        for j in range(1, 7, 1):
            if (i + j) <= 9:
                count += 1

    return Fraction(count,total_combo)
    
    
print(main())