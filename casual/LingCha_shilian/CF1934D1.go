package main

import (
	"bufio"
	. "fmt"
	"io"
	"math/bits"
	"os"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T, n, m int64
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &m)
		if (n ^ m) < n {
			Fprintln(out, 1, n, m)
			continue
		}
		x := (int64(1) << bits.Len(uint(n^(1<<(bits.Len64(uint64(n))-1))))) - 1
		if x < m {
			Fprintln(out, -1)
		} else {
			Fprintln(out, 2, n, x, m)
		}
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
