package main
import (
	"fmt"
	"sort"
)

func largestDivisibleSubset(nums []int) []int {
	// initialize
	dp := make([]int, len(nums))
	prev := make([]int, len(nums))
	res := []int{}
	max_val, index := 1, 0
	for i := 0; i < len(dp); i++ {
		dp[i] = 1
		prev[i] = -1
	}
	sort.Ints(nums)
	// build dp
	for i := 0; i < len(nums); i++ {
		for j := i - 1; j >= 0; j-- {
			if nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i] {
				dp[i] = dp[j] + 1
				prev[i] = j
				if dp[i] > max_val {
					max_val = dp[i]
					index = i
					break
				}
			}
		}
	}
	// build ans
	for index != -1 {
		res = append(res, nums[index])
		index = prev[index]
	}
    
	return res
}

func main() {
	arr1 := []int{1,2,3,4,5,6,7,8,9,10,11,12,13,36}
	arr2 := []int{4,8,10,240}

	fmt.Println(largestDivisibleSubset(arr1))
	fmt.Println(largestDivisibleSubset(arr2))
}