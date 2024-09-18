package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

type node struct {
	lo, ro *node
	sum    int
}

func build(l, r int) *node {
	o := &node{}
	if l == r {
		return o
	}
	m := (l + r) >> 1
	o.lo = build(l, m)
	o.ro = build(m+1, r)
	return o
}

func (o *node) update(ol, or, l, r, add int) {
	if l <= ol && or <= r {
		o.sum += add
		return
	}
	lo, ro := *o.lo, *o.ro
	o.lo, o.ro = &lo, &ro
	if add := o.sum; add > 0 {
		o.lo.sum += add
		o.ro.sum += add
		o.sum = 0
	}
	m := (ol + or) / 2
	if l <= m {
		o.lo.update(ol, m, l, r, add)
	}
	if r > m {
		o.ro.update(m+1, or, l, r, add)
	}
}

func (o *node) query(ol, or, i int) int {
	if ol == or {
		return o.sum
	}
	m := (ol + or) / 2
	if i <= m {
		return o.sum + o.lo.query(ol, m, i)
	}
	return o.sum + o.ro.query(m+1, or, i)
}

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, q, op, l, r, v int
	Fscan(in, &n, &m, &q)
	t := make([]*node, 1, q+1)
	t[0] = build(1, m)
	type pair struct{ i, v int }
	last := make([]pair, n+1)
	for ; q > 0; q-- {
		Fscan(in, &op, &l, &r)
		if op == 1 {
			Fscan(in, &v)
			o := *t[len(t)-1]
			o.update(1, m, l, r, v)
			t = append(t, &o)
		} else if op == 2 {
			last[l] = pair{len(t) - 1, r}
		} else {
			p := last[l]
			Fprintln(out, p.v+t[len(t)-1].query(1, m, r)-t[p.i].query(1, m, r))
		}
	}
}

// type fenwick []int

// func (f fenwick) update(i, val int) {
// 	for ; i < len(f); i += i & -i {
// 		f[i] += val
// 	}
// }

// func (f fenwick) pre(i int) (res int) {
// 	for ; i > 0; i &= i - 1 {
// 		res += f[i]
// 	}
// 	return
// }

// func solve(in io.Reader, _w io.Writer) {
// 	out := bufio.NewWriter(_w)
// 	defer out.Flush()

// 	var n, m, q int
// 	Fscan(in, &n, &m, &q)
// 	type query struct{ l, r, x, op int }
// 	qs := make([]query, q)
// 	for i := range q {
// 		Fscan(in, &qs[i].op)
// 		if qs[i].op == 1 {
// 			Fscan(in, &qs[i].l, &qs[i].r, &qs[i].x)
// 		} else if qs[i].op == 2 {
// 			Fscan(in, &qs[i].l, &qs[i].x)
// 		} else {
// 			Fscan(in, &qs[i].l, &qs[i].r)
// 		}
// 	}

// 	t := make(fenwick, m+1)
// 	todo := make([][]int, n+1)
// 	for i := q - 1; i >= 0; i-- {
// 		q := qs[i]
// 		if q.op == 1 {
// 			t.update(q.l, q.x)
// 			t.update(q.r+1, -q.x)
// 		} else if q.op == 2 {
// 			for _, j := range todo[q.l] {
// 				qs[j].x += t.pre(qs[j].r) + q.x
// 			}
// 			todo[q.l] = todo[q.l][:0]
// 		} else {
// 			qs[i].x = -t.pre(q.r) // 先减去
// 			todo[q.l] = append(todo[q.l], i)
// 		}
// 	}
// 	for _, td := range todo {
// 		for _, j := range td {
// 			qs[j].x += t.pre(qs[j].r)
// 		}
// 	}
// 	for _, q := range qs {
// 		if q.op == 3 {
// 			Fprintln(out, q.x)
// 		}
// 	}
// }

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
