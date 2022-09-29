#QUES LINK -  https://www.hackerrank.com/contests/int213-contest18/challenges/any-or-all

_ = input()
n = input().split()
print(all([int(i) > 0 for i in n]) and any([j == j[::-1] for j in n]))

