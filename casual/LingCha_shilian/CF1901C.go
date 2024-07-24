package main

import (
	"bufio"
	. "fmt"
	"io"
	"math/bits"
	"os"
	"strings"
)

func runCF1902C(in io.Reader, _w io.Writer) {
	var v, n, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		m, M := int(1e9), 0
		for i := 0; i < n; i++ {
			Fscan(in, &v)
			m = min(m, v)
			M = max(M, v)
		}
		if m == M {
			Println(0)
			continue
		}
		u := 1<<bits.Len(uint(M)) - 1
		x := u - M
		ans := 1 + bits.Len(uint((u/2)^((m+x)/2)))
		Println(ans)
		if ans <= n {
			Println(x, strings.Repeat("0 ", ans-1))
		}
	}
}

func main() {
	runCF1902C(bufio.NewReader(os.Stdin), os.Stdout)
}
