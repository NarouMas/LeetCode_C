package main

import "sort"

func minimumDifference(nums []int, k int) int {
	res := 100000
	if k == 1 {
		return 0
	}
	k -= 1
	sort.Ints(nums)
	for i := 0; i < len(nums)-k; i++ {
		res = min(res, nums[i+k]-nums[i])
	}
	return res
}
