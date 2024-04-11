from collections import deque

s = input()
n = int(input())
rev = False
d = deque(s)
for i in range(n):
    query = input()
    if query[0] == '1':
        rev = not rev 
    elif query[0] == '2':
        query = query.split()
        f, c = query[1], query[2]
        if not rev:
            if f == '1':
                d.appendleft(c)
            elif f == '2':
                d.append(c)
        else:
            if f == '2':
                d.appendleft(c)
            elif f == '1':
                d.append(c)
ans = list(d)
if rev:
    ans = reversed(ans)
print(''.join(ans))

