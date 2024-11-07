def dfs(u, v, k, Book, visited, ans, Data):
    n, m = len(Book), len(Book[0])
    visited[u][v] = True
    ans.append((u, v))

    if k == len(Data) - 1:
        return True
        
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    for i in range(4):
        x, y = u + dx[i], v + dy[i]

        if 0 <= x < n and 0 <= y < m and not visited[x][y] and Book[x][y] == Data[k + 1]:
            if dfs(x, y, k + 1, Book, visited, ans, Data):
                return True

    ans.pop()
    visited[u][v] = False
    return False

def main():
    N = 100
    n = int(input())
    Data = list(map(int, input().split()))
    
    m = int(input())
    Book = [list(map(int, input().split())) for _ in range(m)]

    visited = [[False] * N for _ in range(N)]
    ans = []

    found = False
    for i in range(m):
        for j in range(m):
            if Data[0] == Book[i][j]:
                if dfs(i, j, 0, Book, visited, ans, Data):
                    found = True
                    break
        if found:
            break

    if not found or not ans:
        print("error")
    else:
        for u, v in ans:
            print(u, v, end=' ')
        print()

if __name__ == "__main__":
    main()
