def calculate_max_distance(t, M, T):
    if t > T:
        return 0
    
    max_distance = 0
    # Try every possible resting time r from 0 to t
    for r in range(t + 1):
        remaining_time = t - r
        magic_used = min((M + 4 * r) // 10, remaining_time)
        distance = magic_used * 60 + (remaining_time - magic_used) * 17
        max_distance = max(max_distance, distance)
    
    return max_distance

def can_escape(D, T, M):
    left, right = 0, T
    escape_possible = False
    best_time = -1
    
    while left <= right:
        mid = (left + right) // 2
        if calculate_max_distance(mid, M, T) >= D:
            escape_possible = True
            best_time = mid
            right = mid - 1
        else:
            left = mid + 1
    
    if escape_possible:
        return "YES", best_time
    else:
        max_distance = 0
        for t in range(T + 1):
            max_distance = max(max_distance, calculate_max_distance(t, M, T))
        return "NO", max_distance

def solve():
    m, d, t = map(int, input().split())
    result, value = can_escape(d, t, m)
    print(result, value)

if __name__ == '__main__':
    solve()
