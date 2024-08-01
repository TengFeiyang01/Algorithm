import sys
sys.setrecursionlimit(10000000)
def count_longest_sym_substr(s: str) -> int:
    result = 0
    i = 0
    while i < len(s):
        rest_len = len(s) - i
        if result >= rest_len:
            return result
        
        l = i
        r = i + 1
        
        while l >= 0 and r < len(s) and s[l] == "<" and s[r] == ">":
            sub_len = r - l + 1
            result = max(result, sub_len)
            l -= 1
            r += 1

        i = r

    return result

def solution(s: str) -> int:
    
    if "?" not in s:
        return count_longest_sym_substr(s)

    return max(
        solution(s.replace("?", "<", 1)),
        solution(s.replace("?", ">", 1)),
    )
    

print(solution("<"*1000000 + "?" * 100000))
print(solution("<><??>>")) # 4
print(solution("??????")) # 6
print(solution("<<?")) # 2
