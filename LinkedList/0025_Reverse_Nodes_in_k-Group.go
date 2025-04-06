package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k == 1 {
		return head
	}
	dummy := &ListNode{Val: 0, Next: head}
	last_of_prev_group := dummy
	prev := dummy
	cur := head
	for cur != nil {
		var next *ListNode
		// check k remains
		k_remain := true
		temp_node := cur
		for i := 1; i < k; i++ {
			temp_node = temp_node.Next
			if temp_node == nil {
				k_remain = false
				break
			}
		}

		if k_remain {
			fisrt_of_cur_group := cur
			for i := 0; i < k; i++ {
				next = cur.Next
				cur.Next = prev
				prev = cur
				if i != k-1 {
					cur = next
				}
			}
			last_of_prev_group.Next = cur
			last_of_prev_group = fisrt_of_cur_group
			last_of_prev_group.Next = next
		} else {
			last_of_prev_group.Next = cur
			next = cur.Next
			break
		}
		cur = next
	}
	return dummy.Next
}

func main() {
	node1, node2, node3, node4, node5, node6 := &ListNode{Val: 1}, &ListNode{Val: 2}, &ListNode{Val: 3}, &ListNode{Val: 4}, &ListNode{Val: 5}, &ListNode{Val: 6}
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	node5.Next = node6
	res := reverseKGroup(node1, 2)
	for res != nil {
		fmt.Print(res.Val, " ")
		res = res.Next
	}
}
