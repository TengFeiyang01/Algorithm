import datetime
a, b, c = map(int, input().split('/'))
res = set()

def check(y, m, d):
    y = y + (2000 if y < 60 else 1900)
    try:
        res.add(datetime.date(y, m, d).strftime('%Y-%m-%d'))
    except:
        pass


check(a, b, c)
check(c, a, b)
check(c, b, a)

for date in sorted(res):
    print(date)
