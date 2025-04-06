package main
import (
	"container/heap"
	"fmt"
)

type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] > h[j] } // min-heap
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func findKthLargest(nums []int, k int) int {
    h := &IntHeap{}
	heap.Init(h)
	res := 0
	for i := 0; i < len(nums); i++ {
		heap.Push(h, nums[i])
	}
	
	for k > 0 {
		res = heap.Pop(h).(int)
		k--
	}
	return res
}

func main() {
	arr1 := []int{3,2,1,5,6,4}
	fmt.Println(findKthLargest(arr1, 2))
}