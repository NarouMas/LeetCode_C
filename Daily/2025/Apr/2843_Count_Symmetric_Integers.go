package main

import (
	"fmt"
	"math"
)

func countSymmetricIntegers(low int, high int) int {
	res := 0
	for i := low; i <= high; i++ {
		dig := int(math.Floor(math.Log10(float64(i)) + 1))
		add := 0
		count := dig
		n := i
		if dig&1 == 1 {
			continue
		}
		dig /= 2

		for count > 0 {
			if count > dig {
				add += n % 10
			} else {
				add -= n % 10
			}
			n /= 10
			count--
		}
		if add == 0 {
			res++
		}
	}
	return res
}

func main() {
	fmt.Println(countSymmetricIntegers(1, 100))
}
