from collections import deque

n = int(input())
d = deque()
for i in range(n):
    query = input()
    if query[0] == '1':
        query = query.split()
        x, c = int(query[1]), int(query[2])
        d.append((x, c))
    elif query[0] == '2':
        query = query.split()
        c = int(query[1])
        s, count = 0, 0
        while count < c:
            x, temp_c = d.popleft()
            if count + temp_c <= c:
                s += x * temp_c
                count += temp_c
            else:
                s += x * (c - count)
                d.appendleft((x, temp_c - c + count))
                count = c
        print(s)

