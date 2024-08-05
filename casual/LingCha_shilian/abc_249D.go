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

	var n, v int
	const mx = 2e5
	cnt := [mx + 1]int{}
	for Fscan(in, &n); n > 0; n-- {
		Fscan(in, &v)
		cnt[v]++
	}
	ans := 0
	for i := 1; i <= mx; i++ {
		for j := 1; j*i <= mx; j++ {
			ans += cnt[i] * cnt[j] * cnt[i*j]
		}
	}
	Fprintln(out, ans)
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
