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

	var n, T, v int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)

		ans := 0
		mx := 0
		sum := 0
		for i := 0; i < n; i++ {
			Fscan(in, &v)
			mx = max(mx, v)
			sum += v
			if (sum - mx) == mx {
				ans++
			}
		}
		Fprintln(out, ans)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
