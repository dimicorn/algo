n, k = map(int, input().split())

nums = list(map(int, input().split()))
d = {num : 1 for num in nums}

count = 0

for i in d:
    if (i - k) in d:
        count += 1
    if (i + k) in d:
        count += 1
    
print(count // 2)