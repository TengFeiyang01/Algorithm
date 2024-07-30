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

	var x, y, z, T, k int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &x, &y, &z, &k)

		ans := 0
		for a := 1; a <= x; a++ {
			for b := 1; b <= y; b++ {
				c := k / a / b
				if a*b*c == k {
					ans = max(ans, (x-a+1)*(y-b+1)*(z-c+1))
				}
			}
		}
		Fprintln(out, ans)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
