import re

def result(str1, str2):
    pattern = r"[0-9a-f]+"
    valids = re.split(pattern, str1)
    count = len(set(str2))

    ans = []
    for valid in valids:
        if valid != "" and len(set(valid)) <= count:
            ans.append(valid)

    if len(ans) > 0:
        ans.sort(key=lambda x: (-len(set(x)), [-ord(char) for char in x]))
        return ans[0]
    else:
        return "Not Found"

# 测试
print(result(input(), input()))
