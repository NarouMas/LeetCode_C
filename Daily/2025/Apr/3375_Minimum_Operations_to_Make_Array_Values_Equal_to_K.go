package main

func minOperations(nums []int, k int) int {
	arr := make([]bool, 101)
	res := 0
	arr[k] = true
	for i := range nums {
		if nums[i] < k {
			return -1
		} else if arr[nums[i]] == false {
			arr[nums[i]] = true
			res++
		}
	}
	return res
}
