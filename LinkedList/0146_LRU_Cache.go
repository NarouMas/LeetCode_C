package main

import "fmt"

type LRUCache struct {
	capacity int
	length   int
	head     *MyNode
	tail     *MyNode
	vals     map[int]Pair
}

type MyNode struct {
	Key   int
	Check int
	Next  *MyNode
}

type Pair struct {
	Key   int
	Val   int
	Check int
}

func Constructor(capacity int) LRUCache {
	lru := LRUCache{capacity: capacity, length: 0}
	dummy := &MyNode{Key: -1}
	lru.head = dummy
	lru.tail = dummy
	lru.vals = make(map[int]Pair)
	return lru
}

func (this *LRUCache) Get(key int) int {
	val, exists := this.vals[key]
	if exists {
		this.tail.Next = &MyNode{Key: val.Key, Check: val.Check + 1}
		this.tail = this.tail.Next
		this.vals[key] = Pair{Key: val.Key, Val: val.Val, Check: val.Check + 1}
		return val.Val
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	if this.length == this.capacity {
		val, exists := this.vals[key]
		if exists {
			this.vals[key] = Pair{Key: key, Val: value, Check: val.Check + 1}
			this.tail.Next = &MyNode{Key: key, Check: val.Check + 1}
			this.tail = this.tail.Next
		} else {
			for this.head != nil && this.head.Check != this.vals[this.head.Key].Check {
				this.head = this.head.Next
			}
			if this.head != nil {
				delete(this.vals, this.head.Key)
				this.head = this.head.Next
			}
			this.vals[key] = Pair{Key: key, Val: value, Check: 0}
			this.tail.Next = &MyNode{Key: key, Check: 0}
			this.tail = this.tail.Next
			if this.head == nil {
				this.head = this.tail
			}
		}
	} else {
		val, exists := this.vals[key]
		if exists {
			this.vals[key] = Pair{Key: key, Val: value, Check: val.Check + 1}
			this.tail.Next = &MyNode{Key: key, Check: val.Check + 1}
			this.tail = this.tail.Next
		} else {
			this.vals[key] = Pair{Key: key, Val: value, Check: 0}
			this.tail.Next = &MyNode{Key: key, Check: 0}
			this.tail = this.tail.Next
			if this.length == 0 {
				this.head = this.tail
			}
			this.length++
		}
	}
}

func main() {
	obj := Constructor(1)
	fmt.Println(obj.Get(6))
	fmt.Println(obj.Get(8))
	obj.Put(12, 1)
	fmt.Println(obj.Get(2))
	obj.Put(15, 11)
	obj.Put(5, 2)
	obj.Put(1, 15)
	obj.Put(4, 2)
	fmt.Println(obj.Get(5))
	obj.Put(15, 5)
}
