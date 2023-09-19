def check(x):
    count = 0
    for t in str(x):
        if t != '0':
            count += 1
    
    return count == 1


N = 999999
ans = []
res = []
for i in range(1, N+1):
    if check(i):
        ans.append(i)

t = int(input())
for i in range(t):
    n = int(input())
    count = 0
    for j, val in enumerate(ans):
        if val <= n:
            count += 1
    
    res.append(count)

for i in res:
    print(i)