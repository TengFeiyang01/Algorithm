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

	var n, T int
	var s, t string
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &s, &t)
		i := 1
		for i < n && s[i] <= t[i-1] {
			i++
		}
		j := i - 1
		for j > 0 && s[j] == t[j-1] {
			j--
		}
		Fprintln(out, s[:i]+t[i-1:])
		Fprintln(out, i-j)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
