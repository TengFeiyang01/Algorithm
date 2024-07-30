package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"slices"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, T int
	var s []byte
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &s)
		st := []int{}
		for i, b := range s {
			for len(st) > 0 && b > s[st[len(st)-1]] {
				st = st[:len(st)-1]
			}
			st = append(st, i)
		}
		m := len(st)
		t := slices.Clone(s)
		for i, idx := range st {
			t[idx] = s[st[m-i-1]]
		}
		if !slices.IsSorted(t) {
			Fprintln(out, -1)
			continue
		}
		for _, i := range st {
			if s[i] == s[st[0]] {
				m--
			}
		}
		Fprintln(out, m)
	}

}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
