import time


start = input()
end = input()
year = start[:4]
if start > year + year[::-1]:
    year = str(int(year) + 1)

ans = 0
while True:
    year = "0" * (4 - len(year)) + year
    if year + year[::-1] > end:
        break
    try:
        _ = time.strptime(year + year[::-1], "%Y%m%d")
        ans += 1
    except:
        pass

    year = str(int(year) + 1)


print(ans)
