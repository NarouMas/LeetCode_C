package main
import (
	"fmt"
)

func maxAscendingSum(nums []int) int {
	res := 0
	sum := nums[0]
	for i := 1; i < len(nums); i++{
		if nums[i] > nums[i - 1]{
			sum += nums[i]
		} else {
			res = max(res, sum)
			sum = nums[i]
		}
	}

	return max(res, sum)
}

func main(){
	var nums = []int{10, 20, 30, 40, 50}
	fmt.Println(longestMonotonicSubarray(nums))
}