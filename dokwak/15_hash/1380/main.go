package main

import (
	"bufio"
	"fmt"
	"os"
)

func idx(a *[101]int) int {
	for i := 1; i <= 100; i++ {
		if a[i] == 1 {
			return i
		}
	}
	return 0
}

func main() {
	var n int
	var name [101]string
	scn := 1
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Fscan(reader, &n)
		if n == 0 {
			break
		}
		reader.ReadString('\n')
		for i := 1; i <= n; i++ {
			name[i], _ = reader.ReadString('\n')
		}
		var chk [101]int
		for i := 0; i < 2*n-1; i++ {
			var k int
			var s string
			fmt.Fscan(reader, &k, &s)
			chk[k] ^= 1
		}
		fmt.Print(scn, " ", name[idx(&chk)])
		scn++
	}
}
