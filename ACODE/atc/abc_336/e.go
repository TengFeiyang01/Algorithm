package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

const N = 16

var dp [N][150][150]int64
var a [N]int
var len, d int

func dfs(pos, dsum, dval int, limit, lead bool) int64 {
	if pos == 0 {
		if dsum == d && dval == 0 {
			return 1
		}
		return 0
	} else if !limit && !lead && dp[pos][dsum][dval] != -1 {
		return dp[pos][dsum][dval]
	}
	var ans int64 = 0
	up := 9
	if limit {
		up = a[pos]
	}
	for i := 0; i <= up; i++ {
		ans += dfs(pos-1, dsum+i, (dval*10+i)%d, limit && (i == up), lead && (i == 0))
	}
	if !limit && !lead {
		dp[pos][dsum][dval] = ans
	}
	return ans
}

func calc() int64 {
	var ans int64 = 0
	for d = 1; d <= 15*9; d++ {
		for i := range dp {
			for j := range dp[i] {
				for k := range dp[i][j] {
					dp[i][j][k] = -1
				}
			}
		}
		ans += dfs(len, 0, 0, true, true)
	}
	return ans
}
func test(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int64
	fmt.Fscan(in, &n)
	len = 0
	for n > 0 {
		len++
		a[len] = int(n % 10)
		n /= 10
	}
	fmt.Fprintln(out, calc())
}

func main() {
	test(os.Stdin, os.Stdout)
}
