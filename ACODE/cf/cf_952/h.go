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

	var n, m, T int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &m)
		s := make([]string, n)

		groups := n
		maxSize := 1
		fa := make([]int, n*m) // n+1
		sz := make([]int, len(fa))
		for i := range fa {
			fa[i] = i
			sz[i] = 1
		}
		var find func(int) int
		find = func(x int) int {
			if fa[x] != x {
				fa[x] = find(fa[x])
			}
			return fa[x]
		}
		merge := func(from, to int) (newRoot int) {
			from, to = find(from), find(to)
			if from == to {
				return -1
			}
			fa[from] = to
			sz[to] += sz[from]
			if sz[to] > maxSize {
				maxSize = sz[to]
			}
			groups--
			return to
		}

		size := func(x int) int { return sz[find(x)] }

		for i := 0; i < n; i++ {
			Fscan(in, &s[i])
			for j, c := range s[i] {
				if c == '#' {
					if j > 0 && s[i][j-1] == '#' {
						merge(i*m+j, i*m+j-1)
					}
					if i > 0 && s[i-1][j] == '#' {
						merge(i*m+j, (i-1)*m+j)
					}
				}
			}
		}

		ans := 0
		for j := 0; j < m; j++ {
			now := 0
			st := map[int]int{}
			for i := 0; i < n; i++ {
				st[find(i*m+j)] = 1

			}

			if j > 0 {
				for i := 0; i < n; i++ {
					if s[i][j-1] == '#' {
						st[find(i*m+j-1)] = 1
					}
				}
			}
			if j+1 < m {
				for i := 0; i < n; i++ {
					if s[i][j+1] == '#' {
						st[find(i*m+j+1)] = 1
					}
				}
			}
			for k, _ := range st {
				now += size(k)
			}
			ans = max(ans, now)
		}

		for i := 0; i < n; i++ {
			now := 0
			st := map[int]int{}

			for j := 0; j < m; j++ {
				st[find(i*m+j)] = 1
			}

			if i > 0 {
				for j, c := range s[i-1] {
					if c == '#' {
						st[find((i-1)*m+j)] = 1
					}
				}
			}
			if i+1 < n {
				for j, c := range s[i+1] {
					if c == '#' {
						st[find((i+1)*m+j)] = 1
					}
				}
			}
			for k, _ := range st {
				now += size(k)
			}
			ans = max(ans, now)
		}
		Fprintln(out, ans)

	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
