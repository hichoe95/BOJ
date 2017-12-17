n = int(input())
score, seq = 0,0
k = list(map(int, input().split()))
for i in k :
    if i :
        score += seq + 1
        seq += 1
    else :
        seq = 0

print (score)