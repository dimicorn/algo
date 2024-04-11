def solve(n, stocks):
    st, res = [], []
    for stock in stocks:
        count = 1 
        while st and st[-1][0] <= stock:
            count += st.pop()[1]
        st.append((stock, count))
        res.append(count)
    return res 

t = int(input())
ans = []
for i in range(t):
    n = int(input())
    stocks = list(map(int, input().split()))
    ans.append(solve(n, stocks))
for i in ans:
    print(*i)

