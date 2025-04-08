package main

func minimumOperations(nums []int) int {
	arr := make([]bool, 101)
	for i := len(nums) - 1; i >= 0; i-- {
		if arr[nums[i]] {
			return (i + 3) / 3
		} else {
			arr[nums[i]] = true
		}
	}
	return 0
}
