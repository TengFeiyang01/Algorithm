package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func run(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &m)
		a := make([]int, n)
		b := make([]int, m)
		for i := range a {
			Fscan(in, &a[i])
		}
		for i := range b {
			Fscan(in, &b[i])
		}
		sort.Ints(b)
		ans := []any{}
		for i, j := 0, m-1; i < n || j >= 0; i++ {
			for j >= 0 && (i == n || a[i] <= b[j]) {
				ans = append(ans, b[j])
				j--
			}
			if i < n {
				ans = append(ans, a[i])
			}
		}
		Fprintln(out, ans...)
	}
}

func main() {
	run(bufio.NewReader(os.Stdin), os.Stdout)
}
