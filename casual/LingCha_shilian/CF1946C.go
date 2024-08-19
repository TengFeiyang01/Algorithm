package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, T, k, x, y int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &k)
		adj := make([][]int, n)
		for i := 0; i < n-1; i++ {
			Fscan(in, &x, &y)
			x, y = x-1, y-1
			adj[x] = append(adj[x], y)
			adj[y] = append(adj[y], x)
		}
		ans := sort.Search(n/(k+1), func(low int) bool {
			low++
			cnt := 0
			var dfs func(int, int) int
			dfs = func(u, fa int) int {
				s := 1
				for _, v := range adj[u] {
					if v != fa {
						s += dfs(v, u)
					}
				}
				if s >= low {
					cnt++
					return 0
				}
				return s
			}
			if dfs(0, -1) >= low {
				cnt++
			}
			return cnt <= k
		})
		Fprintln(out, ans)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
