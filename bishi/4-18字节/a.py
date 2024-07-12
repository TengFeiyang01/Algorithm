def solve() -> None:
    s = input()
    n = len(s)
    s = list(s)
    a = s[::]
    a.sort()
    if a == s:
        print("".join(s))
        return

    for i in range(n):
        if s[i] != a[i]:
            for j in range(n):
                if a[i] == s[j]:
                    s[i], s[j] = s[j], s[i]
                    print("".join(s))
                    return
        


if __name__ == '__main__':
    solve()
