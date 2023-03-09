def main():
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    res = sorted(a & b)
    for i in res:
        print(i, end=' ')

if __name__ == "__main__":
    main()

