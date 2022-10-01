#QUES LINK - https://www.hackerrank.com/contests/int213-contest19/challenges/bus-station


#submit in Python 3

def solve(a):
    s = sum(a)
    sums = []
    for i in range(len(a)):
        t = (sums or [0])[-1] + a[i]
        if t<=s/2:
            sums.append(t)
        else:
            break
    sums.append(s)
    for i in sums:
        if not s%i:
            t = i
            for j in a:
                t = t or i
                t-= j
                if t<0:
                    break
            else:
                yield i
 

int(input())
a = list(map(int,input().split()))
print(*solve(a))