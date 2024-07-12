def getDigits(s, ptr):
    ret = ""
    while ptr[0] < len(s) and s[ptr[0]].isdigit():
        ret += s[ptr[0]]
        ptr[0] += 1
    return ret

def getString(v):
    return ''.join(v)

def decodeString(s):
    stk = []
    ptr = [0]

    while ptr[0] < len(s):
        cur = s[ptr[0]]
        if cur.isdigit():
            digits = getDigits(s, ptr)
            stk.append(digits)
        elif cur.isalpha() or cur == '(':
            stk.append(s[ptr[0]])
            ptr[0] += 1
        else:
            ptr[0] += 1
            sub = []
            while stk[-1] != '(':
                sub.append(stk.pop())
            sub.reverse()
            stk.pop()
            repTime = int(stk.pop())
            t = ''
            o = getString(sub)
            while repTime > 0:
                t += o
                repTime -= 1
            stk.append(t)

    return getString(stk)

def strStr(s, p):
    n, m = len(s), len(p)
    if m == 0:
        return 0
    s, p = ' ' + s, ' ' + p
    next = [0] * (m + 1)

    for i in range(2, m + 1):
        j = next[i - 1]
        while j and p[i] != p[j + 1]:
            j = next[j]
        if p[i] == p[j + 1]:
            j += 1
        next[i] = j

    j = 0
    for i in range(1, n + 1):
        while j and s[i] != p[j + 1]:
            j = next[j]
        if s[i] == p[j + 1]:
            j += 1
        if j == m:
            return i - m
    return -1

def solve():
    import sys
    t = input()
    s = input()
    original = s
    
    t = decodeString(t)
    
    t = ''.join(['1' if c == 'A' else '0' for c in t])
    s = ''.join(['1' if c.isalpha() else '0' for c in s])

    j = strStr(s, t)
    if j == -1:
        print("!")
    else:
        print(original[j:j + len(t)])

if __name__ == "__main__":
    solve()
