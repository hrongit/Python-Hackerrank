#https://www.hackerrank.com/contests/k21qt-contest33/challenges/validate-list-of-email-address-with-filter

def fun(s):
    valid = True
    
    if s.count('@') != 1:
        return not valid
    else:
        username, rear = s.split('@')
        if len(username)>0:
            for t in username:
                if not (t.isalnum() or t in ['_', '-']):
                    return not valid
        else:
            return not valid
                
        if rear.count(".") != 1:
            return not valid
        else:
            website, extension = rear.split('.')
            if len(extension)>3:
                return not valid
            else:
                for t in extension:
                    if not t.isalpha():
                        return not valid
            
            for t in website:
                if not t.isalnum():
                    return not valid
    return valid



##done 33