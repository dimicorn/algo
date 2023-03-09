def main():
    d = {}
    n = int(input())
    for i in range(n):
        d[i] = set()
        m = int(input())
        for j in range(m):
            d[i].add(input())
    res1 = set()
    res2 = set()
    res1 |= d[0]
    res2 |= d[0]
    for i in range(len(d)):
        res1 &= d[i]
        res2 |= d[i]
    print(len(res1))
    for i in res1:
        print(i)
    print(len(res2))
    for i in res2:
        print(i)

if __name__ == "__main__":
    main()

