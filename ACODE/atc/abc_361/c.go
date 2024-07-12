package main

import (
	"bufio"
	. "fmt"
	"math"
	"os"
	"sort"
)

func solve() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, k int
	Fscan(in, &n, &k)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	sort.Ints(a)
	k = n - k
	ans := math.MaxInt
	for i := k - 1; i < n; i++ {
		if a[i]-a[i-k+1] < ans {
			ans = a[i] - a[i-k+1]
		}
	}
	Fprint(out, ans)
}

func main() {
	solve()
}
