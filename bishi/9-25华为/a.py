def can_complete(reqs, n, target, T):
    total = sum(x for x in reqs if x <= target)
    return total <= T

def max_workload(reqs, T):
    n = len(reqs)
    half = n // 2

    # 分成两部分
    left_part = reqs[:half]
    right_part = reqs[half:]

    # 计算左半部分的所有可能的工作量
    left_sums = {0}
    for req in left_part:
        new_sums = {x + req for x in left_sums}
        left_sums |= new_sums

    # 计算右半部分的所有可能的工作量
    right_sums = {0}
    for req in right_part:
        new_sums = {x + req for x in right_sums}
        right_sums |= new_sums

    max_work = 0
    # 在左半部分和右半部分中寻找最优组合
    for left in left_sums:
        if left <= T:
            # 在右半部分中寻找可以与左半部分配对的工作量
            for right in right_sums:
                if left + right <= T:
                    max_work = max(max_work, left + right)

    return max_work

def main():
    n, T = map(int, input().split())
    requirements = list(map(int, input().split()))
    
    ans = max_workload(requirements, T)
    print(ans)

if __name__ == "__main__":
    main()
