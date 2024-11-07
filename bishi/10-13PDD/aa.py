class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def solve():
    nums = list(map(int, input().split()))[1:]
    nums.sort()
    m, l, r = map(int, input().split())
    ans = cnt = mx = 0
    a = []
    def helper(left, right):
        nonlocal ans, mx, a
        if left > right:
            return None
        
        mid = (left + right) // 2
        root = TreeNode(nums[mid])
        root.left = helper(left, mid - 1)
        root.right = helper(mid + 1, right)
        
        if not root.left and not root.right:
            a.append(root.val)
        
        return root

    helper(0, len(nums) - 1)
    cnt = 0
    mx = max(a)
    for x in a:
        if l <= x <= r:
            cnt += 1
            ans += x
    if cnt == 0:
        ans = mx

    print(ans)


if __name__ == "__main__":
    solve()