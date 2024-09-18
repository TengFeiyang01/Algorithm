mod = 5999993
def get(s):
	res = 0
	for c in s:
		res = (res * 29 + ord(c) - ord('a') + 1) % mod
	return res
def check(n):
	while n:
		if n % 29 > 26 or n % 29 <= 0:
			return False
		n = n // 29
	return True
t = int(input())
for _ in range(t):
	s = input()
	s_h = get(s)
	for i in range(1, 50):
		tep = s_h * pow(29, i, mod)
		tep_1 = (s_h - tep + mod) % mod
		if check(tep_1):
			while tep_1:
				s += chr(tep_1 % 29 + ord('a') - 1)
				tep_1 = tep_1 // 29
			print(s)
			break



# print(pow(29, 5, mod))