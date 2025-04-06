package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	cur := head
	count := 0
	for cur != nil {
		count++
		cur = cur.Next
	}
	dummy := &ListNode{Val: 0, Next: head}
	cur = head
	prev := dummy
	for cur != nil {
		if count == n {
			prev.Next = cur.Next
			break
		}
		prev = cur
		cur = cur.Next
		count--
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
	res := removeNthFromEnd(node1, 2)
	for res != nil {
		fmt.Print(res.Val, " ")
		res = res.Next
	}
}
