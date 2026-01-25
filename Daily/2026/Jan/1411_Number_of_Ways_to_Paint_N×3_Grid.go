package main

import "fmt"

func numOfWays(n int) int {
	mod := 1000000007
	patternA := 6
	patternB := 6
	for i := 2; i <= n; i++ {
		newA := (patternA*3 + patternB*2) % mod
		newB := (patternA*2 + patternB*2) % mod
		patternA = newA
		patternB = newB
	}
	return (patternA + patternB) % mod
}

func main() {
	fmt.Println(numOfWays(1))
}
