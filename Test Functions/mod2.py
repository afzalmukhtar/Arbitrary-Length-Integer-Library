def mod2(x, y):
    
    count = 0
    loop = 0
    while (x - y**count) > 0:
        count+=1
        loop+=1
    count -= 1
    x = x - y**count
    while(x > y):
        loop+=1
        x = x - y**count
        if x < 0:
            x = x + y**count
            count -= 1
    print("LOOP : ", loop)
    print("MOD : ", x)



def mod(x, y):
    length = len(str(x))
    count = 0
    
    loop = 0
    loop2 = 0
    while x > y:
        loop += 1
        count = 0
        while (x - y**count) > 0:
            loop2 += 1
            count+=1
        count -= 1
        x = x - y**count
    print("Outter loop : ", loop)
    print("Inner loop : ", loop2)
    print("MOD : ",x)
    

x = 1234512345123451234512345
y = 1234512345123451234512344
mod(x, y)
mod2(x, y)