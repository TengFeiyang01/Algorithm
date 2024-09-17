def solve():
    def parse(cmds, s, e):
        if s > e:
            return 0
        if cmds[s] == "F0":
            return 4 + parse(cmds, s + 5, e)
        elif cmds[s] == "F1":
            cnt = int(cmds[s + 1], 16)
            len_val = int(cmds[s + 2] + cmds[s + 3] + cmds[s + 4] + cmds[s + 5], 16)
            acc = parse(cmds, s + 6, s + 6 + len_val - 1) * cnt
            return acc + parse(cmds, s + 6 + len_val, e)
        else:
            raise ValueError("Invalid command")
    
    line = input().strip()

    if not line:
        print(0)
    else:
        cmds = line.split()
        try:
            result = parse(cmds, 0, len(cmds) - 1)
            print(result)
        except Exception:
            print(-1)

if __name__ == "__main__":
    solve()
