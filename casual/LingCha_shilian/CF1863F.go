package main

import (
	"bufio"
	. "fmt"
	"io"
	"math/bits"
	"os"
)

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T, n int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		sum := make([]int, n+1)
		for i := 1; i <= n; i++ {
			Fscan(in, &sum[i])
			sum[i] ^= sum[i-1]
		}
		leftBits := make([]int, n)
		for i := 0; i < n; i++ {
			rightBits := 0
			for j := n - 1; j >= i; j-- {
				s2 := sum[j+1] ^ sum[i]
				ok := i == 0 && j == n-1 ||
					rightBits < 0 || rightBits&s2 != 0 ||
					leftBits[j] < 0 || leftBits[j]&s2 != 0
				if ok {
					if s2 == 0 {
						leftBits[j] = -1
						rightBits = -1
					} else {
						high := 1 << (bits.Len(uint(s2)) - 1)
						leftBits[j] |= high
						rightBits |= high
					}
				}
				if i == j {
					if ok {
						Print("1")
					} else {
						Print("0")
					}
				}
			}
		}
		Println()
	}
}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
