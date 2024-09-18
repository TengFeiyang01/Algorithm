package main

import (
	"bufio"
	. "fmt"
	"io"
	"math"
	"os"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m int

	Fscan(in, &n, &m)
	v := make([]int, n)
	w := make([]int, n)

	for i := range v {
		Fscan(in, &w[i], &v[i])
	}

	const N = 100000
	dp := make([]int, N+1)
	for i := range dp {
		dp[i] = math.MaxInt / 2
	}

	dp[0] = 0
	for i := range v {
		for j := N; j >= v[i]; j-- {
			if dp[j - v[i]] + w[i] < dp[j] {
				dp[j] = dp[j - v[i]] + w[i]
			}
		}
	}

	for j := N; j >= 0; j-- {
		if dp[j] <= m {
			Fprintln(out, j)
			break
		}
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
