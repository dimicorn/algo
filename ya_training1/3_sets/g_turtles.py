def main():
    n = int(input())
    s = set()
    ss = set()
    for i in range(n):
        s.add(tuple(map(int, input().split())))
    for i in range(n):
        ss.add((i, n - i - 1))
    count = 0
    for i in s:
        if i in ss:
            count += 1
    print(count)



if __name__ == "__main__":
    main()

