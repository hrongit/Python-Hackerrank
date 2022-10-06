#ques link - https://www.hackerrank.com/contests/int213-contest23/challenges/merge-the-tools

def merge_the_tools(string, k):
    for part in zip(*[iter(string)] * k):
        d = dict()
        print(''.join([ d.setdefault(c, c) for c in part if c not in d ]))


