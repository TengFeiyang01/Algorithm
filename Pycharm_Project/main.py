import itertools

a = [1, 2, 3, 4, 5, 6, 7, 8, 1, 3, 5, 7, 2, 4, 6, 8, 1, 4, 7, 2, 5, 8, 3, 6, 1, 5, 2, 7, 4, 8]
ok = True
for i in range(1, 9):
    for j in range(i+1, 9):
        print(i, j)
