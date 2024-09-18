package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func test(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	l := make([]int, n)
	r := make([]int, n)
	l[0] = 1
	r[n-1] = 1
	for i := 1; i < n; i++ {
		l[i] = min(l[i-1]+1, a[i])
	}
	for i := n - 2; i >= 0; i-- {
		r[i] = min(r[i+1]+1, a[i])
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans = max(ans, min(l[i], r[i]))
	}
	fmt.Fprint(out, ans)
}

func main() { test(os.Stdin, os.Stdout) }