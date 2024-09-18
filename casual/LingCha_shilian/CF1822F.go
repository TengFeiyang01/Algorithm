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

	var n, c, k, T, w, v int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &k, &c)
		adj := make([][]int, n)
		for i := 1; i < n; i++ {
			Fscan(in, &v, &w)
			v--
			w--
			adj[v] = append(adj[v], w)
			adj[w] = append(adj[w], v)
		}
		nodes := make([]struct{ maxD, maxD2, my int }, n)
		var dfs func(int, int) int
		dfs = func(u, fa int) int {
			p := &nodes[u]
			for _, v := range adj[u] {
				if v == fa {
					continue
				}
				d := dfs(v, u) + k
				if d > p.maxD {
					p.maxD2 = p.maxD
					p.maxD = d
					p.my = v
				} else if d > p.maxD2 {
					p.maxD2 = d
				}
			}
			return p.maxD
		}
		ans := dfs(0, -1)

		var reroot func(int, int, int, int)
		reroot = func(u, fa, fromUp, cost int) {
			p := nodes[u]
			ans = max(ans, max(fromUp, p.maxD)-cost)
			for _, v := range adj[u] {
				if v == fa {
					continue
				}
				except := p.maxD
				if v == p.my {
					except = p.maxD2
				}
				reroot(v, u, max(fromUp, except)+k, cost+c)
			}
		}
		reroot(0, -1, 0, 0)
		Fprintln(out, ans)
	}

}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
