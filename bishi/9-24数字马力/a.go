package main

import (
	"bufio"
	"container/heap"
	. "fmt"
	"io"
	"math"
	"os"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	const mod = 998244353
	defer out.Flush()
	var n, m, k int
	Fscan(in, &n, &m, &k)
	adj := make([][]neighbor, n)
	for i := 0; i < m; i++ {
		var u, v, w int
		Fscan(in, &u, &v, &w)
		adj[u-1] = append(adj[u-1], neighbor{v - 1, w})
		adj[v-1] = append(adj[v-1], neighbor{u - 1, w})
	}
	edges := make([]neighbor, k)
	for i := range edges {
		var v, w int
		Fscan(in, &v, &w)
		edges[i] = neighbor{v - 1, w}
	}
	
	ori := make([]neighbor, 0)
	for i := range adj[0] {
		ori = append(ori, adj[0][i])
	}
	for i := 0; i < k; i++ {
		adj[0] = append(adj[0], edges[i])
	}
	d := dijkstra(adj, 0)
	var check = func(x int) bool {
		cur := make([]neighbor, 0)
		cur = append(cur, ori...)
		cur = append(cur, edges[:x]...)
		adj[0] = cur
		d1 := dijkstra(adj, 0)
		for i := 1; i < n; i++ {
			if d[i] != d1[i] {
				return false
			}
		}
		return true
	}

	l, r := 0, k
	for l < r {
		mid := l + r>>1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	Fprintln(out, k-l)
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}

// 以下为 Dijkstra 算法模板
type neighbor struct{ to, weight int }

func dijkstra(g [][]neighbor, start int) []int {
	dist := make([]int, len(g))
	for i := range dist {
		dist[i] = math.MaxInt
	}
	dist[start] = 0
	h := hp{{start, 0}}
	for len(h) > 0 {
		p := heap.Pop(&h).(pair)
		x := p.x
		if dist[x] < p.dist {
			continue
		}
		for _, e := range g[x] {
			y := e.to
			if d := dist[x] + e.weight; d < dist[y] {
				dist[y] = d
				heap.Push(&h, pair{y, d})
			}
		}
	}
	return dist
}

type pair struct{ x, dist int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dist < h[j].dist }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() (v any)      { a := *h; *h, v = a[:len(a)-1], a[len(a)-1]; return }
