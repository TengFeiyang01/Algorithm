mod = 5999993
n = 5999993
ans = []
while n:
	ans.append(n % 29)
	n = n // 29
print(*ans[::-1])
"c"
c1 = "caiztjx"
c2 = "cficzo"
tep = []
ans1 = 0
for c in c1:
	tep.append(ord(c) - ord("a") + 1)
	ans1 = ans1 * 29 + ord(c) - ord("a") + 1
print(*tep)
print(ans1)
ans2 = 0
tep = []
for c in c2:
	tep.append(ord(c) - ord("a") + 1)
	ans2 = ans2 * 29 + ord(c) - ord("a") + 1
print(*tep)
print(ans2)
cha = abs(ans1 - ans2)
y = cha % mod
print(cha)
print(y)