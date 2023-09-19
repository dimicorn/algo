n, x = map(int, input().split())

arr = list(map(int, input().split()))
d = dict()
flag = True

for i in range(n):
    dif = x - arr[i]
    if dif in d:
        print(d[dif] + 1, i + 1)
        flag = False
        break
    d[arr[i]] = i

if flag:
    print(-1)