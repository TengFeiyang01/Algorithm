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

	var T, n, k int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &k)
		a := make([]int, n)
		f := make([][11]int, n+1)
		for i := range a {
			Fscan(in, &a[i])
			for j := 0; j <= k; j++ {
				res := f[i][j] + a[i]
				mn := a[i]
				for l := i - 1; l >= max(i-j, 0); l-- {
					mn = min(mn, a[l])
					t := i - l
					res = min(res, f[l][j-t]+mn*(t+1))
				}
				f[i+1][j] = res
			}
		}
		Fprintln(out, f[n][k])
	}
}

// func solve(in io.Reader, _w io.Writer) {
// 	out := bufio.NewWriter(_w)
// 	defer out.Flush()

// 	var T, n, k int
// 	for Fscan(in, &T); T > 0; T-- {
// 		Fscan(in, &n, &k)
// 		a := make([]int, n)
// 		for i := range a {
// 			Fscan(in, &a[i])
// 		}
// 		memo := make([][11]int, n)
// 		for i := range memo {
// 			for j := range memo[i] {
// 				memo[i][j] = -1
// 			}
// 		}
// 		var dfs func(int, int) int
// 		dfs = func(i, j int) int {
// 			if i < 0 {
// 				return 0
// 			}
// 			p := &memo[i][j]
// 			if *p != -1 {
// 				return *p
// 			}
// 			res := dfs(i-1, j) + a[i]
// 			mn := a[i]
// 			for l := i - 1; l >= max(i-j, 0); l-- {
// 				mn = min(mn, a[l])
// 				t := i - l
// 				res = min(res, dfs(l-1, j-t)+mn*(t+1))
// 			}
// 			*p = res
// 			return res
// 		}
// 		Fprintln(out, dfs(n-1, k))
// 	}
// }

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
