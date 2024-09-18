from datetime import * 
begin = input()
year = begin[:4]
if year + year[::-1] <= begin:
    year = str(int(year) + 1)

ans1 = -1
ans2 = -1

while ans2 == -1:
    try:
        datetime.strptime(year + year[::-1], "%Y%m%d")
        if ans1 == -1:
            ans1 = year + year[::-1]
        if ans2 == -1 and year[:2] == year[2:] and year[0] != year[1]:
            ans2 = year + year[::-1]
    except:
        pass
    year = str(int(year) + 1)


print(ans1)
print(ans2)
