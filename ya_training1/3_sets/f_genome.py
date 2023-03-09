def main():
    dct1 = {}
    dct2 = {}
    a = input()
    b = input()
    for i in range(1, len(a)):
        if dct1.get(a[i-1:i+1]) is not None:
            dct1[a[i-1:i+1]] += 1
        else:
            dct1[a[i-1:i+1]] = 1
    for i in range(1, len(b)):
        if dct2.get(b[i-1:i+1]) is not None:
            dct2[b[i-1:i+1]] += 1
        else:
            dct2[b[i-1:i+1]] = 1
    summ = 0
    for i in dct1:
        if i in dct2:
            summ += dct1[i]
    print(summ)


if __name__ == "__main__":
    main()

