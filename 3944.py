t = int(input())

def ToDecimal(a,b) :
    ret, r = 0, 1
    while a != 0 :
        ret += r*(a%10)
        a //= 10
        r *= b
    return ret

for _ in range(t) :
    b,d = map(int, input().split())
    print(ToDecimal(d,b)%(b-1))

