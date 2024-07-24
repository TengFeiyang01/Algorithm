package main

import (
	"bufio"
	"container/heap"
	. "fmt"
	"io"
	"os"
	"slices"
	"sort"
)

func cf1935C_2(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T, n, lim int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &lim)
		type pair struct{ a, b int }
		a := make([]pair, n)
		for i := range a {
			Fscan(in, &a[i].a, &a[i].b)
		}
		slices.SortFunc(a, func(p, q pair) int { return p.b - q.b })

		ans := 0
		f := make([]int, n)
		for j, p := range a {
			f[j] = p.a - p.b
			if p.a <= lim {
				ans = 1
			}
		}
		for i := 1; i < n; i++ {
			mn := f[i-1]
			for j := i; j < n; j++ {
				f[j], mn = mn+a[j].a, min(mn, f[j])
				if f[j]+a[j].b <= lim {
					ans = i + 1
				}
			}
		}
		Fprintln(out, ans)
	}
}

func cf1935C(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T, n, lim int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &lim)
		type pair struct{ a, b int }
		a := make([]pair, n)
		for i := range a {
			Fscan(in, &a[i].a, &a[i].b)
		}
		slices.SortFunc(a, func(p, q pair) int { return p.b - q.b })

		ans := 0
		for i, p := range a {
			if p.a <= lim {
				ans = max(ans, 1)
			}
			h := hp{}
			s := 0
			// 即使 a[j] 出堆 此时总和是s + p.a - a[j'].b + a[i].b 比目前的还小 所以不会影响答案
			for j := i - 1; j >= 0 && p.a+p.b-a[j].b < lim; j-- {
				q := a[j]
				heap.Push(&h, q.a)
				s += q.a
				for h.Len() > 0 && p.a+p.b-q.b+s > lim {
					s -= heap.Pop(&h).(int)
				}
				ans = max(ans, 1+h.Len())
			}
		}
		Fprintln(out, ans)
	}
}

func main() {
	// cf1935C(bufio.NewReader(os.Stdin), os.Stdout)
	cf1935C_2(bufio.NewReader(os.Stdin), os.Stdout)
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any          { a := h.IntSlice; v := a[len(a)-1]; h.IntSlice = a[:len(a)-1]; return v }
