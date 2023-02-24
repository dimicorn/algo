import sys


def solve(arr):
    max1 = -sys.maxsize
    max2 = -sys.maxsize
    max3 = -sys.maxsize

    min1 = sys.maxsize
    min2 = sys.maxsize

    if len(arr) == 3:
        return arr
    
    for i, val in enumerate(arr):
        if val > max1:
            max3 = max2
            max2 = max1
            max1 = val
        elif val <= max1 and val > max2:
            max3 = max2
            max2 = val
        elif val <= max2 and val > max3:
            max3 = val
        
        if val < min1:
            min2 = min1
            min1 = val
        elif val >= min1 and val < min2:
            min2 = val
    
    if max1 * max2 * max3 > max1 * min1 * min2:
        return (max3, max2, max1)
    else:
        return (min1, min2, max1)
        




a = list(map(int, input().split()))
ans = solve(a)
for i in ans:
    print(i, end=' ')
