package main
import (
	"fmt"
)

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func maximumSum(nums []int) int {
	myMap := make(map[int]int)
	res := -1
	for i := 0; i < len(nums); i++ {
		sum := 0
		copy := nums[i]
		for copy > 0 {
			sum += copy % 10
			copy /= 10
		}
		value, exists := myMap[sum]
		if exists {
			res = max(res, value + nums[i])
			if nums[i] > value {
				myMap[sum] = nums[i]
			}
		} else {
			myMap[sum] = nums[i]
		}
	} 
	return res
}

func main() {
	nums := []int{18,43,36,13,7}
	fmt.Println(maximumSum(nums))
}