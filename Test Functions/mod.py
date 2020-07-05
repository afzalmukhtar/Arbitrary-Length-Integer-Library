
def mod(a, b):
    loop = 0
    x = len(str(a)) + len(str(b)) - 3
    p = int(str(a)[len(str(a)) - x : ])
    x = 10 ** x
    mod = 0
    while x != 0:
        loop+=1
        if (a - 12*p) > 0:
            p = p + x
        else:
            p = p - x
            x = x//10
    print(loop)
    return (a - 12*p)
        
    

x = 76798 * 12 + 1
mod(x, 12)
