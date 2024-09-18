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

	var n int
	var s, t []byte
	Fscan(in, &n, &s, &t)
	pre := -2
	ans := 0
	for i, b := range s {
		if b == t[i] {
			continue
		}
		if pre == i-1 && b != s[pre] {
			pre = -2
		} else {
			ans++
			pre = i
		}
	}
	Fprint(out, ans)
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
