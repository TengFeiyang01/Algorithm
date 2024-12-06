class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        cur, last = 0, 0
        ret = []
        for i in range(len(s)):
            cur += 1 if s[i] == '1' else -1
            if cur == 0:
                ret.append('1' + self.makeLargestSpecial(s[last + 1 : i]) + '0')
                last = i + 1
        return ''.join(sorted(ret, reverse=True))

s = input()
s = s.replace('(', '1')
s = s.replace(')', '0')
ans = Solution().makeLargestSpecial(s)
ans = ans.replace('1', '(')
ans = ans.replace('0', ')')
print(ans) 