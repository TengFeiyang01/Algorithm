package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func test(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	s := "L"
	for i := 0; i < n; i++ {
		s += "o"
	}
	s += "ng"
	fmt.Println(s)
}

func main() { test(os.Stdin, os.Stdout) }
