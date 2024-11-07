k = int(input())
s = input()
n = len(s)
a = []
i = j = 0
while i < n:
	if s[i].isdigit():
		j = i
		while j < n and s[j].isdigit():
			j += 1
		a.append(int(s[i:j]))
		i = j
	else:
		i += 1
a.sort(reverse=True)
if len(a) >= k:
	print(a[k-1])
else:
	print("N")