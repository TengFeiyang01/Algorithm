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

	var n, T, h int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &h, &n)
		a := make([]int, n)
		c := make([]int, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		for i := range c {
			Fscan(in, &c[i])
		}

		var check func(int) bool
		check = func(t int) bool {
			now := 0
			for i, x := range a {
				y := c[i]
				now += x * (1 + t/y)
				if now >= h {
					return true
				}
			}
			return now >= h
		}

		l, r := 0, 1119999800001
		for l < r {
			mid := (l + r) >> 1
			if check(mid) {
				r = mid
			} else {
				l = mid + 1
			}
		}
		Fprintln(out, l+1)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
