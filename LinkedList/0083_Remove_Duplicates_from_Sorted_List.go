package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	dummy := &ListNode{Val: -101, Next: head}
	prev := dummy
	cur := head
	for cur != nil {
		if cur.Val == prev.Val {
			prev.Next = cur.Next
		} else {
			prev = cur
		}
		cur = cur.Next
	}
	return dummy.Next
}

func main() {
	node1, node2, node3, node4, node5, node6 := &ListNode{Val: 1}, &ListNode{Val: 2}, &ListNode{Val: 2}, &ListNode{Val: 4}, &ListNode{Val: 5}, &ListNode{Val: 5}
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	node5.Next = node6
	res := deleteDuplicates(node1)
	for res != nil {
		fmt.Print(res.Val, " ")
		res = res.Next
	}
}
