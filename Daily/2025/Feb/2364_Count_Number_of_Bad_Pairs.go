package main
import (
	"fmt"
)

func countBadPairs(nums []int) int64 {
    count := make(map[int]int)
	all := len(nums)
	res := int64(0)
	for i := 0; i < len(nums); i++ {
		nums[i] = nums[i] - i
		count[nums[i]]++
	}
	for _, value := range count {
		all -= value
		res += int64(all * value)
	}
	return res
}

func main(){
	var nums = []int{4, 1, 3, 3}
	fmt.Println(countBadPairs(nums))
}