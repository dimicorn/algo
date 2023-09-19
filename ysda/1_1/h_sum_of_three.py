n, x = map(int, input().split())

arr = list(map(int, input().split()))

for i, val in enumerate(arr):
    arr[i] = (val, i)

arr = sorted(arr)
flag = True
for l in range(n):
    m = l + 1
    r = n - 1
    while m < r:
        s = arr[l][0] + arr[m][0] + arr[r][0]
        if s == x:
            print(arr[l][1] + 1, arr[m][1] + 1, arr[r][1] + 1)
            flag = False
            break
        elif s > x:
            r -= 1
        else:
            m += 1

if flag:
    print('IMPOSSIBLE')