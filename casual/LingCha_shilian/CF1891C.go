package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"slices"
)

func runCF1891C(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T, n, s int
	for Fscan(in, &T); T > 0; T-- {
		s = 0
		Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			Fscan(in, &a[i])
			s += a[i]
		}

		slices.Sort(a)

		left := (s + 1) / 2
		ans := left
		for i, v := range a {
			if left < v {
				ans += n - i
				break
			}
			left -= v
		}
		Fprintln(out, ans)

	}
}

func main() {
	runCF1891C(bufio.NewReader(os.Stdin), os.Stdout)
}
