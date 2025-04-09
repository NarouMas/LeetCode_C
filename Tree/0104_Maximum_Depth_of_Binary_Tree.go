package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var qu []*TreeNode
	res := 0
	qu = append(qu, root)
	for len(qu) > 0 {
		res++
		for i := len(qu); i > 0; i-- {
			node := qu[0]
			qu = qu[1:]
			if node.Left != nil {
				qu = append(qu, node.Left)
			}
			if node.Right != nil {
				qu = append(qu, node.Right)
			}
		}
	}
	return res
}
