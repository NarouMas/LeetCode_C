package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	if head == nil {
		return head
	}
	var arr []*ListNode
	cur, prev := head, &ListNode{}
	for cur != nil {
		arr = append(arr, cur)
		prev = cur
		cur = cur.Next
		prev.Next = nil
	}
	dummy := &ListNode{Val: -1}
	cur = dummy
	for i := range arr {
		if arr[i].Val < x {
			cur.Next = arr[i]
			cur = cur.Next
		}
	}
	for i := range arr {
		if arr[i].Val >= x {
			cur.Next = arr[i]
			cur = cur.Next
		}
	}
	return dummy.Next
}

func main() {
	node1, node2, node3, node4, node5, node6 := &ListNode{Val: 6}, &ListNode{Val: 9}, &ListNode{Val: 3}, &ListNode{Val: 4}, &ListNode{Val: 1}, &ListNode{Val: 6}
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	node5.Next = node6
	res := partition(node1, 3)
	for res != nil {
		fmt.Print(res.Val, " ")
		res = res.Next
	}
}
