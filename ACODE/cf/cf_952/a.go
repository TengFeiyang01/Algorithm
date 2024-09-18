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

	var T int
	for Fscan(in, &T); T > 0; T-- {
		var a, b []byte
		Fscan(in, &a, &b)
		Fprintln(out, string(string(b[:1])+string(a[1:])), string(string(a[:1])+string(b[1:])))
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
