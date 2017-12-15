n = input()
d = list(map(int, input().split()))

l = [0]*10
ans = 1
for i in range(len(d)) :
    for j in range(i):
        print(j)
        if(d[i]%d[j] == 0):
            d[i]//= j
    ans *= d[i]

print(ans)