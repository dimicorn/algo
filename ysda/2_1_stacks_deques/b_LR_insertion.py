from collections import deque

n = int(input())
s = input()
ans = deque([n])
for i in range(n-1, -1, -1):
    if s[i] == 'L':
        ans.append(i)
    else:
        ans.appendleft(i)
print(*ans) 

