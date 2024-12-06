class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def solve():
    nums = list(map(int, input().split()))
    m, l, r = map(int, input().split())
    ans = cnt = 0
    def helper(left, right):
        nonlocal ans
        if left > right:
            return None
        mid = (left + right) // 2
        root = TreeNode(nums[mid])
        root.left = helper(left, mid - 1)
        root.right = helper(mid + 1, right)
        if not root.left and not root.right and l <= root.val <= r:
            cnt += 1
            ans += root.val
        return root
    helper(0, len(nums) - 1)
    
    print(ans)


if __name__ == "__main__":
    solve()