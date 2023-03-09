def main():
    dict = {}
    n = int(input())
    for i in range(n):
        (a, b) = tuple(map(str, input().split()))
        dict[a] = b
        dict[b] = a
    word = input()
    print(dict[word])

if __name__ == "__main__":
    main()

