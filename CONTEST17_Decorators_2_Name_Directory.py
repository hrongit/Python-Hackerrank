#QUES LINK - https://www.hackerrank.com/contests/int213-contest17/challenges/decorators-2-name-directory


import operator
def person_lister(func):
    def inner(people):
        return [func(p) for p in sorted(people, key = lambda x: (int(x[2])))]
    return inner
@person_lister
def name_format(person):
    return ("Mr. " if person[3] == "M" else "Ms. ") + person[0] + " " + person[1]