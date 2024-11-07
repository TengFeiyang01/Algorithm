import sys
import math

def main():
    sys.setrecursionlimit(1 << 25)
    N = int(input())
    P = list(map(int, input().split()))
    P = P[:2*N]

    total_contestants = 2 * N

    # 分割为前一半和后一半
    first_half = P[:N]
    second_half = P[N:]

    # 计算每一半中的最大战斗力
    max_first_half = max(first_half)
    max_second_half = max(second_half)

    # 记录每个选手所在的半区
    position = [0] * (total_contestants + 1)  # 1-indexed
    for idx, p in enumerate(P):
        position[p] = 1 if idx < N else 2

    # 初始化结果数组
    results = [0] * (total_contestants + 1)  # 1-indexed

    # 计算每个选手的最大胜场
    for i in range(1, total_contestants + 1):
        max_wins = 0

        # 尝试将选手 i 交换到前一半
        max_wins_first_half = 0
        new_max_first_half = max_first_half
        if position[i] != 1:
            # 如果选手 i 不在前一半，尝试交换
            if i > max_first_half:
                # 交换后，选手 i 是前一半的最强者
                new_max_first_half = i
                max_wins_first_half = int(math.log2(N))
                # 判断决赛能否获胜
                if i > max_second_half:
                    max_wins_first_half += 1
            else:
                # 交换后，选手 i 不是最强者
                stronger_players = sum(1 for p in first_half if p > i)
                max_wins_first_half = int(math.log2(N)) - int(math.log2(stronger_players + 1))
        else:
            # 选手 i 已在前一半
            if i == max_first_half:
                max_wins_first_half = int(math.log2(N))
                if i > max_second_half:
                    max_wins_first_half += 1
            else:
                stronger_players = sum(1 for p in first_half if p > i)
                max_wins_first_half = int(math.log2(N)) - int(math.log2(stronger_players + 1))

        # 尝试将选手 i 交换到后一半
        max_wins_second_half = 0
        new_max_second_half = max_second_half
        if position[i] != 2:
            # 如果选手 i 不在后一半，尝试交换
            if i > max_second_half:
                # 交换后，选手 i 是后一半的最强者
                new_max_second_half = i
                max_wins_second_half = int(math.log2(N))
                if i > max_first_half:
                    max_wins_second_half += 1
            else:
                # 交换后，选手 i 不是最强者
                stronger_players = sum(1 for p in second_half if p > i)
                max_wins_second_half = int(math.log2(N)) - int(math.log2(stronger_players + 1))
        else:
            # 选手 i 已在后一半
            if i == max_second_half:
                max_wins_second_half = int(math.log2(N))
                if i > max_first_half:
                    max_wins_second_half += 1
            else:
                stronger_players = sum(1 for p in second_half if p > i)
                max_wins_second_half = int(math.log2(N)) - int(math.log2(stronger_players + 1))

        # 取最大值
        max_wins = max(max_wins_first_half, max_wins_second_half)
        results[i] = max_wins

    # 输出结果
    print(' '.join(map(str, results[1:])))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        main()
