#https://www.hackerrank.com/contests/int213-contest32/challenges/validating-the-phone-number

import re
for _ in range(int(input())):
    if re.match(r'[789]\d{9}$',input()):   
        print('YES')  
    else:  
        print('NO')