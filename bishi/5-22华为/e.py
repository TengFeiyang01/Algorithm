def solve() -> None:
    s = input()
    ans = 0
    if s[0] == '-':
        for i in range(2, len(s)):
            if s[i] != '0':
                ans = max(ans, -int(s[1:i])+int(s[i:]))
    else:
        for i in range(1, len(s)):
            if s[i] != '0':
                ans = max(ans, int(s[:i])+int(s[i:]))
    print(ans)
if __name__ == '__main__':
    solve()