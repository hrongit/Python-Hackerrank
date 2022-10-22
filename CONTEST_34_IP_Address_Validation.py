#https://www.hackerrank.com/contests/int213-contest34/challenges/ip-address-validation

import re
N=int(input())
for i in range(N):
    n=input()
    ipv4=r'^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$'
    ipv6=r'^(([0-9a-fA-F]{1,4})\:){7}([0-9a-fA-F]{1,4})$'
    if re.search(ipv4,n):
        print('IPv4')
    elif re.search(ipv6,n):
        print('IPv6')
    else:
        print('Neither')