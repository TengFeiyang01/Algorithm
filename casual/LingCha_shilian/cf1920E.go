package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	const mod = 998244353
	defer out.Flush()
	var n, T, k int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &k)
		memo := make([][]int, n+1)
		for i := range memo {
			memo[i] = make([]int, k)
			for j := range memo[i] {
				memo[i][j] = -1
			}
		}
		var dfs func(int, int) int
		dfs = func(i, j int) int {
			if i == 0 {
				return 1
			}
			p := &memo[i][j]
			if *p != -1 {
				return *p
			}
			res := 0
			for x := 0; x+j < k && (x+1)*(j+1) <= i; x++ {
				res += dfs(i-(x+1)*(j+1), x)
			}
			*p = res % mod
			return *p
		}
		ans := 0
		for j := 0; j < k; j++ {
			ans += dfs(n, j)
		}
		Fprintln(out, ans%mod)
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
