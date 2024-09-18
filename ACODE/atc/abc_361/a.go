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

	var n, k, x int
	Fscan(in, &n, &k, &x)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
		Fprint(out, a[i], " ")
		if i == k-1 {
			Fprint(out, x, " ")
		}
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
