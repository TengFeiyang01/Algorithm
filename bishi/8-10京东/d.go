package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func run(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var ans, res, n, t, x int
	mp := make(map[int]int)
	for Fscan(in, &n, &t); n > 0; n-- {
		Fscan(in, &x)
		ans += mp[t-x]
		if x*2 == t {
			res++
		}
		mp[x]++
	}
	Fprintln(out, ans*2+res)
}

func main() {
	run(bufio.NewReader(os.Stdin), os.Stdout)
}
