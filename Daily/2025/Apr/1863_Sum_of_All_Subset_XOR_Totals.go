package main
import (
	"fmt"
)

func foo(nums []int, depth int, num int, index int) int {
	if depth == 0 {
		return num
	}
	sum := 0
	for i := index; i <= len(nums) - depth; i++ {
		sum += foo(nums, depth - 1, num ^ nums[i], i + 1)
	}
	return sum
}

func subsetXORSum(nums []int) int {
    res := 0
	for i := 1; i <= len(nums); i++ {
		res += foo(nums, i, 0, 0)
	}
	return res
}

func main() {
	arr1 := [] int{5, 1, 6}
	arr2 := [] int{3, 4, 5, 6, 7, 8}
	arr3 := [] int{3, 4, 5, 6, 7, 8, 1, 2, 3, 5, 6, 8}

	fmt.Println(subsetXORSum(arr1))
	fmt.Println(subsetXORSum(arr2))
	fmt.Println(subsetXORSum(arr3))
}