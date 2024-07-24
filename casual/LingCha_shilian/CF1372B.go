package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func runCF1372B(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		ok := false
		for i := 2; i*i <= n; i++ {
			if n%i == 0 {
				ok = true
				Fprintln(out, n/i, n-n/i)
				break
			}
		}
		if !ok {
			Fprintln(out, "1", n-1)
		}
	}
}

func main() {
	runCF1372B(bufio.NewReader(os.Stdin), os.Stdout)
}
