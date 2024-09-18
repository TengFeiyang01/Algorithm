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

	var n int64
	fmt.Fscan(in, &n)
	if n == 1 {
		fmt.Println("0")
		return
	}
	n -= 1
	s := make([]byte, 0)
	for n > 0 {
		s = append(s, byte((n%5)*2))
		n /= 5
	}
	for i := len(s) - 1; i >= 0; i-- {
		fmt.Print(s[i])
	}
}

func main() { test(os.Stdin, os.Stdout) }
