package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	Fscan(in, &n)
	type edge struct{ to, w int }
	adj := make([][]edge, n)
	s := 0

	for i := 0; i < n-1; i++ {
		var x, y, z int
		Fscan(in, &x, &y, &z)
		x--
		y--
		s += z * 2
		adj[x] = append(adj[x], edge{y, z})
		adj[y] = append(adj[y], edge{x, z})
	}

	ans := 0
	t := -1

	var dfs func(int, int, int)
	dfs = func(u, fa, d int) {
		for _, e := range adj[u] {
			v, w := e.to, e.w
			if v == fa {
				continue
			}
			dfs(v, u, d+w)
		}
		if d > ans {
			ans = d
			t = u
		}
	}
	dfs(0, -1, 0)
	dfs(t, -1, 0)

	Fprint(out, s-ans)
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
