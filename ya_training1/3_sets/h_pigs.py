def main():
    n = int(input())
    s = set()
    for i in range(n):
        (a, b) = tuple(map(int, input().split()))
        s.add(a)
    print(len(s))



if __name__ == "__main__":
    main()

