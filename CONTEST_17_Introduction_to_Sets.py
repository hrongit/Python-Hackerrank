
#QUES LINK - https://www.hackerrank.com/contests/int213-contest17/challenges/py-introduction-to-sets

def average(array):
    sum_array = sum(set(array))
    len_array = len(set(array))
    output = sum_array/len_array
    return output

   