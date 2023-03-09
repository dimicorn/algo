def main():
    (n, m) = map(int, input().split())
    ann = set()
    bor = set()
    for i in range(n):
        ann.add(int(input()))
    for i in range(m):
        bor.add(int(input()))
    intersect = sorted(ann & bor)
    dif1 = sorted(ann.difference(bor))
    dif2 = sorted(bor.difference(ann))
    print(len(intersect))
    for i in intersect:
        print(i, end=' ')
    print()
    print(len(dif1))
    for i in dif1:
        print(i, end=' ')
    print()
    print(len(dif2))
    for i in dif2:
        print(i, end=' ')


if __name__ == "__main__":
    main()

