n = int(input())

while n!=0 :
    l = []
    flag = True
    for i in range(n) :
        l.append(int(input()))
    l.append(1422)
    l.sort()
    for j in range(n-1) :
        if 200 < l[j+1] - l[j] :
            flag = False
            break
    if (l[n] - l[n-1]) * 2 > 200 :
        flag = False
    if flag :
        print("POSSIBLE")
    else :
        print("IMPOSSIBLE")
    n = int(input())