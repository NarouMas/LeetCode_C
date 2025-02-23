package main
import (
	"fmt"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	node := &TreeNode{Val: preorder[0]}
	// fmt.Println(preorder[0])
	// fmt.Println("pre:", preorder)
	// fmt.Println("pos:", postorder)
	if len(preorder) > 1 {
		index := -1
		for i := 0; i < len(postorder); i++ {
			if postorder[i] == preorder[1] {
				index = i + 1
				break
			}
		}
		// fmt.Println("index:", index)
		right_len := len(postorder) - index - 1
		node.Left = constructFromPrePost(preorder[1:len(preorder) - right_len], postorder[:len(preorder) - right_len - 1])
		node.Right = constructFromPrePost(preorder[len(preorder) - right_len:], postorder[len(preorder) - right_len - 1:len(postorder) - 1])
	}
	return node
}

func main() {
	arr1 := []int{1,2,4,5,6,7,3,8,9}
	arr2 := []int{5,7,6,4,2,9,8,3,1}

	fmt.Println(constructFromPrePost(arr1, arr2))
}