0 1 2 3 4 5 6 7 8 9 10 11 12 13
a c a c a b a a c a c  a  b  a

i, j, k = 0, 1, 0

s[i + k] > s[j + k]


i, j, k = 0, 1, 0  || s[i + k] < s[j + k] => j = j + 1



i, j, k = 0, 2, 3

k = 3
i
0 1 2 3 4 5 6 7 8 9 10 11 12 13
a c a c a b a a c a c  a  b  a
    j

s[i + k] = c
s[j + k] = b

c > b

s[i + k] > s[j + k] ==> s[i : i+k] || i = i + k + 1
s[i + k] < s[j + k] ==> s[j : j+k] || j = j + k + 1


s[i + k] == s[j + k] || k++

i, j, k = 1, 2, 0

while i <= n and j <= n:
    for k = 0 and k < n and s[i + k] == s[j + k]: k++
    if s[i + k] > s[j + k]: i = i + k + 1
    elif s[i + k] < s[j + k]: j = j + k + 1
    if i == j: i++

min(i, j)
