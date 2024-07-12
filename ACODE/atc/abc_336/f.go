package main

import (
	"bufio"
	"fmt"
	"os"
)

func rotate(s [][]int, x, y, n, m int) [][]int {
	t := make([][]int, n)
	for i := range t {
		t[i] = make([]int, m)
		for j := 0; j < m; j++ {
			t[i][j] = s[i][j]
		}
	}

	for a, c := x, x+n-2; a < x+n-1; a, c = a+1, c-1 {
		for b, d := y, y+m-2; b < y+m-1; b, d = b+1, d-1 {
			s[a][b] = t[c][d]
		}
	}
	return s
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)

	s := make([][]int, n)
	for i := range s {
		s[i] = make([]int, m)
		for j := range s[i] {
			fmt.Fscan(in, &s[i][j])
		}
	}

	type state struct {
		s    [][]int
		u    int
		last int
	}

	var dfs func(state, int, map[string]int) map[string]int
	dfs = func(st state, typeVal int, mp map[string]int) map[string]int {
		key := fmt.Sprintf("%v", st.s)
		if _, exists := mp[key]; !exists {
			mp[key] = st.u
		} else {
			if mp[key] > st.u {
				mp[key] = st.u
			}
		}
		if st.u == 10 {
			return mp
		}

		for i := 0; i < 4; i++ {
			if i == st.last {
				continue
			}
			t := make([][]int, n)
			for i := range st.s {
				t[i] = make([]int, m)
				copy(t[i], st.s[i])
			}

			switch i {
			case 0:
				st.s = rotate(st.s, 0, 0, n, m)
			case 1:
				st.s = rotate(st.s, 0, 1, n, m)
			case 2:
				st.s = rotate(st.s, 1, 0, n, m)
			case 3:
				st.s = rotate(st.s, 1, 1, n, m)
			}

			mp = dfs(state{st.s, st.u + 1, i}, typeVal, mp)
			st.s = t
		}

		return mp
	}

	mp1 := dfs(state{s, 0, -1}, 0, make(map[string]int))
	now := 1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			s[i][j] = now
			now++
		}
	}
	mp2 := dfs(state{s, 0, -1}, 1, make(map[string]int))

	res := 30
	for k, v := range mp1 {
		if val, ok := mp2[k]; ok {
			if res > v+val {
				res = v + val
			}
		}
	}

	if res > 20 {
		res = -1
	}
	fmt.Fprintln(out, res)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(in, out)
}
