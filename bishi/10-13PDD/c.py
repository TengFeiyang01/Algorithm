import sys

def next_multiset_string(s):
    st = [0] * 26

    if len(s) < 26:
        for ch in s:
            st[ord(ch) - ord('a')] += 1
        for i in range(26):
            if st[i] == 0:
                s += chr(ord('a') + i)
                break
        return s
    else:
        s_list = list(s)
        for i in range(25, -1, -1):
            st[ord(s_list[i]) - ord('a')] += 1
            for j in range(ord(s_list[i]) - ord('a') + 1, 26):
                if st[j] == 1:
                    s_list[i] = chr(ord('a') + j)
                    new_s = ''.join(s_list[:i+1])
                    remaining = [chr(ord('a') + x) for x in range(26) if st[x] == 0]
                    remaining.sort()
                    # if remaining:
                        # new_s += remaining[0]
                    return new_s
        return s

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = int(data[idx])
    idx +=1
    results = []
    for _ in range(T):
        if idx >= len(data):
            break
        s = data[idx]
        idx +=1
        result = next_multiset_string(s)
        results.append(result)
    for res in results:
        print(res)

if __name__ == "__main__":
    main()
