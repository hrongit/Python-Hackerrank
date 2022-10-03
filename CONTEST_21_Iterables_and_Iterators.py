#QUES LINK - https://www.hackerrank.com/contests/int213-k21-contest21/challenges/iterables-and-iterators



from itertools import combinations

N = int(input())
LETTERS = list(input().split(" "))
K = int(input())

TUPLES = list(combinations(LETTERS, K))
CONTAINS = [word for word in TUPLES if "a" in word]

print(len(CONTAINS)/len(TUPLES))