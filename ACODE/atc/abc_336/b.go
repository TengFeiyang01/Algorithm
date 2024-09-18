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
	ans := 0
	for now := n & -n; now != 1; now >>= 1 {
		ans += 1
	}
	println(ans)
}

func main() { test(os.Stdin, os.Stdout) }
