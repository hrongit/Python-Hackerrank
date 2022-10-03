#ques link - https://www.hackerrank.com/contests/int213-k21-contest21/challenges/exceptions


for i in range(int(input())):
    try:
        a, b = map(int, input().split())
        print(a//b)
    except Exception as e:
        print("Error Code:",e)