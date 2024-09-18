package main

import (
	"bufio"
	"container/heap"
	. "fmt"
	"io"
	"math"
	"os"
)

func run(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m int
	Fscan(in, &n, &m)
	type edge struct{ to, wt, inv int }
	adj := make([][]edge, n)
	for ; m > 0; m-- {
		var v, w, wt int
		Fscan(in, &v, &w, &wt)
		v--
		w--
		adj[v] = append(adj[v], edge{w, wt, 0})
		adj[w] = append(adj[w], edge{v, wt, 1})
	}

	dis := make([][2]int, n)
	for i := 1; i < n; i++ {
		dis[i] = [2]int{math.MaxInt, math.MaxInt}
	}
	h := hp{data{0, 0, 0}}

	for len(h) > 0 {
		p := heap.Pop(&h).(data)
		if p.dis > dis[p.v][p.inv] {
			continue
		}
		for _, e := range adj[p.v] {
			w, eInv := e.to, e.inv
			newD := p.dis + e.wt
			if (eInv == 1 || p.inv == 0) && newD < dis[w][eInv] {
				dis[w][eInv] = newD
				// Fprintln(out, p.v + 1, w + 1, newD, eInv)
				heap.Push(&h, data{newD, w, eInv})
			}
		}
	}

	for _, d := range dis[1:] {
		res := min(d[0], d[1])
		if res == math.MaxInt {
			res = -1
		}
		Fprint(out, res, " ")
	}

}

func main() {
	run(bufio.NewReader(os.Stdin), os.Stdout)
}

type data struct{ dis, v, inv int }
type hp []data

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(data)) }
func (h *hp) Pop() (v any)      { a := *h; *h, v = a[:len(a)-1], a[len(a)-1]; return }
