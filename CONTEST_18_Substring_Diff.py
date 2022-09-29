#Ques LINK - https://www.hackerrank.com/contests/int213-contest18/challenges/substring-diff


def l_func(p,q,max_s):
    n = len(q)
    res_ar = [0]
    count = 0
    ans = 0
    for i in range(n):
        if(p[i]!=q[i]):
            res_ar.append(i+1)
            count += 1
            if(count>max_s):
                l = res_ar[-1]-res_ar[-2-max_s]-1
                if(l>ans):ans = l
    if(count<=max_s):
        return n
    return ans

def check_func(p,q,s):
    n = len(q)
    ans = 0
    for i in range(n):
        if(n-i<=ans):break
        l = l_func(p,q[i:],s)
        if(l>ans):
            ans = l
    for i in range(n):
        if(n-i<=ans):break
        l = l_func(q,p[i:],s)
        if(l>ans):
            ans = l
    return ans
for case_t in range(int(input())):
    str_s,p,q = input().strip().split()
    s = int(str_s)
    print(check_func(p,q,s))