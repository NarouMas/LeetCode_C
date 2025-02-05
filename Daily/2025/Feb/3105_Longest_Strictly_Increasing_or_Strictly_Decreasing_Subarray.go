package main
import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestMonotonicSubarray(nums []int) int {
    var res int = 1
	var inc int = 1
	var des int = 1
	for i := 1; i < len(nums); i++{
		if nums[i] > nums[i - 1]{
			inc++
		}else {
			inc = 1
		}
		if nums[i] < nums[i - 1]{
			des++
		}else {
			des = 1
		}

		res = max(res, max(inc, des))
	}
	return res
}

func main(){
	var nums = []int{10, 20, 30, 40, 50}
	fmt.Println(longestMonotonicSubarray(nums))
}