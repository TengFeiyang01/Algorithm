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

	var T, n, v int
	const mod = 1_000_000_007
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		a := make([]int, n)
		to := make([]int, n+1)
		has := make([]bool, n+1)
		for i := range a {
			Fscan(in, &a[i])
		}
		for _, v := range a {
			Fscan(in, &to[v])
		}

		for i := 0; i < n; i++ {
			Fscan(in, &v)
			has[v] = true
		}
		ans := 1
		vis := make([]bool, n+1)
		for i := 1; i <= n; i++ {
			if vis[i] {
				continue
			}
			vis[i] = true
			allZero := !has[i]
			for x := to[i]; x != i; x = to[x] {
				vis[x] = true
				if has[x] {
					allZero = false
				}
			}
			if allZero && i != to[i] {
				ans = ans * 2 % mod
			}
		}
		Fprintln(out, ans)
	}

}

func main() {
	run(bufio.NewReader(os.Stdin), os.Stdout)
}
