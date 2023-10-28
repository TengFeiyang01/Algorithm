class Node:
    __slots__ = "l", "r", "mid", "val", "left", "right"

    def __init__(self, l: int, r: int):
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.val = -1
        self.left = None
        self.right = None


def pushUp(node: Node):
    node.val = max(node.left.val, node.right.val)


def pushDown(node: Node):
    if node.left is None:
        node.left = Node(node.l, node.mid)
    if node.right is None:
        node.right = Node(node.mid + 1, node.r)


class Seg:
    def __init__(self):
        self.root = Node(0, int(1e9))

    def update(self, x, val, node: 'Node' = None):
        if node is None:
            node = self.root
        if node.l == x and node.r == x:
            node.val = max(node.val, val)
            return
        pushDown(node)
        if x <= node.mid:
            self.update(x, val, node.left)
        else:
            self.update(x, val, node.right)
        pushUp(node)

    def query(self, l, r, node: 'Node' = None):
        if node is None:
            node = self.root
        if l <= node.l and node.r <= r:
            return node.val
        pushDown(node)
        ans = -1
        if l <= node.mid:
            ans = max(ans, self.query(l, r, node.left))
        if r > node.mid:
            ans = max(ans, self.query(l, r, node.right))
        return ans



