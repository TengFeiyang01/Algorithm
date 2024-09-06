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
	var n, s, x, mn int
	Fscan(in, &n)
	mn = int(2e9)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			Fscan(in, &x)
			s += x
			if i+j == n-1 {
				mn = min(mn, x)
			}
		}
	}
	Fprintln(out, s-mn)
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
