import math
 
K1, M, K2, P2, N2 = map(int, input().split())
K2 -= 1
K1 -= 1
 
if N2 > M:
    print(-1, -1)
elif P2==1 and N2==1: 
    if K1 <= K2: 
        print(1, 1)
    else: 
        min_apart = K2 + 1 
        if K1 < min_apart * M: 
            print(1, 0)
        else: 
            if M == 1: 
                print(0, 1)
            else: 
                print(0, 0)
else:
    floors2 = (P2-1)*M + (N2-1)
    max_apart = K2 // floors2
    if max_apart == 0:
        print(-1, -1)
    else:
        min_apart = math.ceil((K2 + 1) / (floors2 + 1))
        if min_apart > max_apart:
            print(-1, -1)
        else:
            min_floors1 = K1 // min_apart
            minP1 = min_floors1 // M 
            minN1 = min_floors1 % M 
 
            max_floors1 = K1 // max_apart 
            maxP1 = max_floors1 // M 
            maxN1 = max_floors1 % M 
 
            P1 = minP1 + 1 if minP1 == maxP1 else 0
            N1 = minN1 + 1 if minN1 == maxN1 or M == 1 else 0
            print(P1, N1)