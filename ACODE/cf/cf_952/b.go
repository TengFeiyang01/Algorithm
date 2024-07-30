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

	var T, n, x int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		ans := 0
		for i := 2; i <= n; i++ {
			t := n / i
			if i*(1+t)*t/2 > ans {
				ans = i * t * (1 + t) / 2
				x = i
			}
		}
		Fprintln(out, x)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
