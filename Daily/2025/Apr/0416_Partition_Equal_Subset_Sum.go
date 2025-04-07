package main

import (
	"fmt"
)

func canPartition(nums []int) bool {
	sum := 0
	//sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}
	if sum&1 == 1 {
		return false
	}
	sum = sum >> 1
	dp := make([][]bool, len(nums)+1)
	for i := range dp {
		dp[i] = make([]bool, sum+1)
	}
	dp[0][0] = true
	for i := 1; i <= len(nums); i++ {
		for j := 1; j <= sum; j++ {
			if dp[i-1][j] {
				dp[i][j] = true
			} else if j-nums[i-1] >= 0 && dp[i-1][j-nums[i-1]] {
				dp[i][j] = true
			}
		}
		if dp[i][sum] {
			return true
		}
	}
	return dp[len(nums)][sum]
}

func main() {
	arr1 := []int{2, 2, 3, 4, 4, 5, 5, 5, 6, 6, 8, 10}
	fmt.Println(canPartition(arr1))
}
