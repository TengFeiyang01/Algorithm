package main

import (
	"bufio"
	. "fmt"
	"io"

	"os"
)

func run(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, T, x int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			Fscan(in, &x)
			for x > 0 {
				if x%2 == 1 {
					a[i]++
					x--
				}
				if x > 0 {
					x >>= 1
					a[i]++
				}
			}
		}
		p, q := 0, 0
		for i := n - 1; i >= 0; i-- {
			if i > 0 {
				a[i] -= a[i-1]
			}
			if a[i] > 0 {
				p += a[i]
			} else {
				q -= a[i]
			}
		}
		if p < q {
			p = q
		}
		Fprintln(out, p)
	}
}

func main() {
	run(bufio.NewReader(os.Stdin), os.Stdout)
}
