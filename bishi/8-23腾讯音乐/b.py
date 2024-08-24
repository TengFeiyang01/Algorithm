from collections import deque

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def complete_binary_tree(root):
    if not root:
        return None
    mx = 0
    from collections import defaultdict
    
    def dfs(u: TreeNode, id):
        nonlocal mx
        mx = max(mx, id)
        if not u: return
        if u.left: dfs(u.left, id * 2)
        if u.right: dfs(u.right, id * 2 + 1)

    dfs(root, 1)

    def get(u: TreeNode, id):
        if id * 2 <= mx:
            if not u.left:
                u.left = TreeNode(1)
            get(u.left, id * 2)
        
        if id * 2 + 1 <= mx:
            if not u.right:
                u.right = TreeNode(1)
            get(u.right, id * 2 + 1)
        return u
    return get(root, 1)
