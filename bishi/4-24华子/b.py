class Entry:
    def __init__(self, c, id):
        self.x = 0  # Count of '1's
        self.y = 0  # Maximum consecutive '1's
        self.c = c  # Original string
        self.id = id  # Identifier
        cnt = 0
        for ch in c:
            if ch == '1':
                cnt += 1
                self.x += 1
            else:
                cnt = 0
            self.y = max(self.y, cnt)

    def __lt__(self, other):
        if self.x != other.x:
            return other.x - self.x  # Sort by x in descending order
        elif self.y != other.y:
            return other.y - self.y  # Sort by y in descending order
        elif self.c != other.c:
            return self.c > other.c
        else:
            return self.id - other.id  # Sort by id in ascending order


def solve():
    n, m = map(int, input().split())
    s = list(input().split())
    a = []
    for i in range(n):
        entry = Entry(s[i], i + 1)
        a.append(entry)

    a.sort()

    for i in range(n - 1):
        print(a[i].id, end=" ")
    print(a[n - 1].id)


if __name__ == "__main__":
    solve()
