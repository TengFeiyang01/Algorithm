class T:
    def __init__(self, e, v):
        self.e = e
        self.v = v

class Node:
    def __init__(self):
        self.left = None
        self.right = None
        self.val = 0

def dfs(arr, d):
    left, right = [], []
    for t in arr:
        if len(t.e) > d:
            if t.e[d] == '0':
                left.append(t)
            else:
                right.append(t)

    cur = Node()
    if len(left) > 0:
        cur.left = dfs(left, d + 1)
        cur.val += cur.left.val
    if len(right) > 0:
        cur.right = dfs(right, d + 1)
        cur.val += cur.right.val
    if len(left) == 0 and len(right) == 0:
        cur.val = arr[0].v

    return cur

def solve(leaf, vals):
    n = len(leaf)
    arr = [T(leaf[i], vals[i]) for i in range(n)]

    root = dfs(arr, 0)

    que = [root]
    res = []
    while que:
        cur = que.pop(0)
        if cur is None:
            res.append("#")
            continue
        res.append(str(cur.val))
        que.append(cur.left)
        que.append(cur.right)

    return res
