package main

import (
	"math"
)

func IsPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}

	limit := int(math.Sqrt(float64(n)))
	for i := 5; i <= limit; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}

	return true
}

func countPrimeSetBits(left int, right int) int {
	res := 0
	for i := left; i <= right; i++ {
		count := 0
		n := i
		for n > 0 {
			if n&1 == 1 {
				count++
			}
			n = n >> 1
		}
		if IsPrime(count) {
			res++
		}
	}
	return res
}
