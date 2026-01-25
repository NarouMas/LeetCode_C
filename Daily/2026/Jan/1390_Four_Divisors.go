package main

import "fmt"

func sumFourDivisors(nums []int) int {
	m := make(map[int]int)
	ans := 0
	for _, n := range nums {
		val, ok := m[n]
		if ok {
			ans += val
			continue
		}
		sum, count := 0, 0
		for i := 1; i*i <= n; i++ {
			if n%i == 0 {
				count++
				sum += i
				otherNum := n / i
				if otherNum != i {
					count++
					sum += otherNum
				}
			}
			if count > 4 {
				break
			}
		}
		if count != 4 {
			sum = 0
		}
		m[n] = sum
		ans += sum
	}
	return ans
}

func main() {
	a := []int{1, 2, 3}
	fmt.Println(sumFourDivisors(a))
}
