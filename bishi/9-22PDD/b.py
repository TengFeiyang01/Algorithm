def solve():
    t = int(input())  # 读取测试用例的数量
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        found = False

        # 三重循环，暴力搜索
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    if a[i] == a[j] - a[k]:
                        found = True
                        break
                if found:
                    break
            if found:
                break

        if found:
            print("yes")
        else:
            print("no")


if __name__ == "__main__":
    solve()
