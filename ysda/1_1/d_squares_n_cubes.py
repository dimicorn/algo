def solve(n):
    s = set()
    i = 1
    while i * i * i <= n:
        s.add(i * i * i)
        i += 1
    i = 1
    while i * i <= n:
        s.add(i * i)
        i += 1
    return len(s)

t = int(input())
ans = []
for i in range(t):
    n = int(input())
    ans.append(solve(n))

for i in ans:
    print(i)