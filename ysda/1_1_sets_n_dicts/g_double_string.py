def solve(n, s, d):
    ans = ""
    for i in range(n):
        check = False
        for j in range(1, len(s[i])):
            pref = s[i][:j]
            suff = s[i][j:len(s[i])]
            if pref in d and suff in d:
                check = True
        
        if check:
            ans += '1'
        else:
            ans += '0'
    
    return ans

t = int(input())
res = []

for i in range(t):
    n = int(input())
    d = dict()
    s = []
    for j in range(n):
        tmp = input()
        s.append(tmp)
        d[tmp] = True
    res.append(solve(n, s, d))

for i in res:
    print(i)
