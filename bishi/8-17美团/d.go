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

	var n, m int
	Fscan(in, &m, &n)
	cnt := make([]int, m+2)
	cnt2 := make([]int, m+2)
	a := make([][2]int, n)
	for i := range a {
		Fscan(in, &a[i][0], &a[i][1])
		cnt[a[i][0]]++
		cnt[a[i][1]+1]--
	}
	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
		cnt2[i] += cnt2[i-1]
		if cnt[i] >= 2 {
			cnt2[i]++
		}
	}
	ans := 0
	for i := range a {
		l, r := a[i][0], a[i][1]
		if cnt2[r]-cnt2[l-1] == r-l+1 {
			ans++
		}
	}
	Fprintln(out, ans)
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
