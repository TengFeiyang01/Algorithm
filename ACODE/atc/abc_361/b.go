package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

type Cuboid struct {
	a, b, c, d, e, f int
}

// min returns the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// max returns the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// intersects checks if two cuboids intersect and have a positive volume
func intersects(c1, c2 Cuboid) bool {
	// Find the range of coordinates for each cuboid
	x1Min, x1Max := min(c1.a, c1.d), max(c1.a, c1.d)
	y1Min, y1Max := min(c1.b, c1.e), max(c1.b, c1.e)
	z1Min, z1Max := min(c1.c, c1.f), max(c1.c, c1.f)

	x2Min, x2Max := min(c2.a, c2.d), max(c2.a, c2.d)
	y2Min, y2Max := min(c2.b, c2.e), max(c2.b, c2.e)
	z2Min, z2Max := min(c2.c, c2.f), max(c2.c, c2.f)

	// Check if there is overlap in all three dimensions
	return (x1Min < x2Max && x1Max > x2Min) &&
		(y1Min < y2Max && y1Max > y2Min) &&
		(z1Min < z2Max && z1Max > z2Min)
}

func solve(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var a, b Cuboid
	Fscan(in, &a.a, &a.b, &a.c, &a.d, &a.e, &a.f)
	Fscan(in, &b.a, &b.b, &b.c, &b.d, &b.e, &b.f)
	if intersects(a, b) {
		Fprint(out, "Yes")
	} else {
		Fprint(out, "No")
	}

}

func main() {
	solve(bufio.NewReader(os.Stdin), os.Stdout)
}
