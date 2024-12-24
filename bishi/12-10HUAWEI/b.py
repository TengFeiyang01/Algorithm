

def solve():
    s = input()
    
    k = int(input())

    map = {}
    temp = s[0]
    count = 1
    map[temp] = count

    for i in range(1, len(s)):
        temp = s[i]
        if temp == s[i - 1]:
            count += 1
        else:
            count = 1
        if temp in map:
            map[temp] = max(map[temp], count)
        else:
            map[temp] = count

    ints = list(map.values())
    ints.sort()
    if k > len(ints):
        print(-1)
        return
    print(ints[-k])


if __name__ == '__main__':
    solve()