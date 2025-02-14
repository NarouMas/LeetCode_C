package main
import (
	"fmt"
)

type ProductOfNumbers struct {
    arr []int
	z int
}


func Constructor() ProductOfNumbers {
    p := new(ProductOfNumbers)
	p.z = -1
	return *p
}


func (this *ProductOfNumbers) Add(num int)  {
    if num == 0 {
		this.z = len(this.arr)
		this.arr = append(this.arr, 1)
	} else if len(this.arr) == 0 {
		this.arr = append(this.arr, num)
	} else {
		this.arr = append(this.arr, this.arr[len(this.arr) - 1] * num)
	}
}


func (this *ProductOfNumbers) GetProduct(k int) int {
	if k >= len(this.arr) - this.z {
		return 0
	}
	if len(this.arr) - 1 - k >= 0 {
		return this.arr[len(this.arr) - 1] / this.arr[len(this.arr) - 1 - k]
	} 
	return this.arr[len(this.arr) - 1]
}

func main() {
	obj := Constructor()
	obj.Add(0)
	obj.Add(0)
	obj.Add(9)
	fmt.Println(obj.GetProduct(3))
	obj.Add(8)
	obj.Add(3)
	obj.Add(8)
	fmt.Println(obj.GetProduct(5))
	fmt.Println(obj.GetProduct(4))
	fmt.Println(obj.GetProduct(6))
	obj.Add(8)
	obj.Add(8)
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */