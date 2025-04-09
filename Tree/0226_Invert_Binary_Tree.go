package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	var qu []*TreeNode
	qu = append(qu, root)
	for len(qu) > 0 {
		for i := len(qu); i > 0; i-- {
			node := qu[0]
			qu = qu[1:]
			if node.Left != nil {
				qu = append(qu, node.Left)
			}
			if node.Right != nil {
				qu = append(qu, node.Right)
			}
			node.Left, node.Right = node.Right, node.Left
		}
	}
	return root
}
