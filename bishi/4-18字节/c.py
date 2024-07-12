from bisect import*

nums = list(map(int, input().split()))
m = len(nums)
N = int(input())
nums.sort(reverse = True)

def check(k):
    ans = 0
    check = [0] * m
    for i in range(m):
        if check[i] == 1:
            continue
        ans += 1
        cur_sum = 0
        j = i
        while j < m:
            if check[j] == 1:
                j += 1
                continue
            if nums[j] + cur_sum > k:
                j += 1
            else:
                cur_sum += nums[j]
                check[j] = 1
                j += 1
    return ans <= N

print(bisect_right(range(100000000), False, N, key=check))