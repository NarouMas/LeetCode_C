package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	res, maxValue, curLevel := 1, root.Val, 1
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		sum := 0
		levelSize := len(queue)
		for i := 0; i < levelSize; i++ {
			cur := queue[0]
			queue = queue[1:]
			sum += cur.Val

			if cur.Left != nil {
				queue = append(queue, cur.Left)
			}
			if cur.Right != nil {
				queue = append(queue, cur.Right)
			}
		}
		if sum > maxValue {
			res = curLevel
			maxValue = sum
		}
		curLevel++
	}
	return res
}
