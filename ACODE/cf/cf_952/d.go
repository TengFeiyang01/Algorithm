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

	var n, m, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &m)
		a := make([]string, n)

		l, r, u, d := m, 0, n, 0
		for i := range a {
			Fscan(in, &a[i])
			for j, c := range a[i] {
				if c == '#' {
					l = min(l, j)
					r = max(r, j)
					u = min(u, i)
					d = max(u, i)
				}
			}
		}
		Fprintln(out, (u+d)/2+1, (r+l)/2+1)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
