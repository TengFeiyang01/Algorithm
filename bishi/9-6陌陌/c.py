def solve(words):
    def dfs(cur, remain):
        global res
        if len(cur) > len(res):
            res = cur[:]
        
        last = cur[-1][-1]
        for i, word in enumerate(remain):
            if word[0] == last:
                dfs(cur + [word], remain[:i] + remain[i+1:])

    global res
    res = []
    
    for i, word in enumerate(words):
        dfs([word], words[:i] + words[i+1:])
    
    return res

print(solve(list(input().split())))
