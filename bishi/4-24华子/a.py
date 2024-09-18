alls = list(map(int, input().split()))
alls.sort()
n = len(alls)
x = int(input())
def find(l, r):
    mid = l + r >> 1
    if x == alls[mid]:
        return True
    elif x > alls[mid]:
        print("R", end = "")
        return find(mid + 1, r)
    else:
        print("L", end = "")
        return find(l, mid - 1)
print("S", end = "")
ans = find(0, n - 1)
if ans:
    print("Y")
else:
    print("N")