package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func pow(x, y, mod int) int {
	res := 1
	for y > 0 {
		if y%2 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		y >>= 1
	}
	return res
}

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	const mod = 1000000007
	var k, l, r, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &l, &r, &k)

		// 不能产生进位 ni*k < 10
		x := ((10 + k - 1) / k)
		Fprintln(out, (pow(x, r, mod)-pow(x, l, mod)+mod)%mod)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
