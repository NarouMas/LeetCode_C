package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	var qu_left []*TreeNode
	var qu_right []*TreeNode
	qu_left = append(qu_left, root.Left)
	qu_right = append(qu_right, root.Right)

	for len(qu_left) > 0 || len(qu_right) > 0 {
		for i := len(qu_left); i > 0; i-- {
			left, right := qu_left[0], qu_right[0]
			qu_left, qu_right = qu_left[1:], qu_right[1:]
			if left == nil && right == nil {
				continue
			} else if left == nil && right != nil {
				return false
			} else if right == nil && left != nil {
				return false
			} else {
				if left.Val != right.Val {
					return false
				}
				qu_left = append(qu_left, left.Left)
				qu_left = append(qu_left, left.Right)
				qu_right = append(qu_right, right.Right)
				qu_right = append(qu_right, right.Left)
			}
		}
	}
	return true
}
