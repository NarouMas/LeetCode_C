package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	cur, count := head, 0
	tail, res := &ListNode{}, &ListNode{}
	for true {
		count++
		if cur.Next != nil {
			cur = cur.Next
		} else {
			tail = cur
			break
		}
	}
	k = count - (k % count)
	if k == count {
		return head
	}
	cur = head
	for i := 0; i < k-1; i++ {
		cur = cur.Next
	}
	tail.Next = head
	res = cur.Next
	cur.Next = nil

	return res
}

func main() {
	node1, node2, node3, node4, node5, node6 := &ListNode{Val: 1}, &ListNode{Val: 2}, &ListNode{Val: 3}, &ListNode{Val: 4}, &ListNode{Val: 5}, &ListNode{Val: 6}
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	node5.Next = node6
	res := rotateRight(node1, 3)
	for res != nil {
		fmt.Print(res.Val, " ")
		res = res.Next
	}
}
