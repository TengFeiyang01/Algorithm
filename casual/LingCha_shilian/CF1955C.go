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

	var n, k, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &k)
		s := 0
		a := make([]int, n)
		for i := 0; i < n; i++ {
			Fscan(in, &a[i])
			s += a[i]
		}
		if k >= s {
			Fprintln(out, n)
			continue
		}
		t := (k + 1) / 2
		for l := 0; l < n && t > 0; l++ {
			if a[l] <= t {
				t -= a[l]
				a[l] = 0
			} else {
				a[l] -= t
				break
			}
		}
		t = k / 2
		for r := n - 1; r >= 0 && t > 0; r-- {
			if a[r] <= t {
				t -= a[r]
				a[r] = 0
			} else {
				a[r] -= t
				break
			}
		}
		ans := 0
		for i := range a {
			if a[i] == 0 {
				ans++
			}
		}
		Fprintln(out, ans)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
