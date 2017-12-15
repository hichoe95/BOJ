
n,m = map(int, input().split())
p = list(map(int, input().split()))

dirty = 0
bad = 0
accbad = 0
dp = [[0]*n for _ in range(n)]

for i in range(n) :
    for j in range(1,m) :
        for k in range(1,j) :
