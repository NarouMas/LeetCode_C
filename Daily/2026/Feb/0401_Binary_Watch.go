package main

import (
	"fmt"
)

func foo(current_hour int, current_min int, index int, depth int, res *[]string) {
	time := []int{1, 2, 4, 8, 16, 32, 1, 2, 4, 8}
	if depth == 0 {
		s := fmt.Sprintf("%d:%02d", current_hour, current_min)
		*res = append(*res, s)
		return
	}
	for ; index < len(time); index++ {
		if index <= 5 {
			if current_min+time[index] < 60 {
				foo(current_hour, current_min+time[index], index+1, depth-1, res)
			}
		} else {
			if current_hour+time[index] < 12 {
				foo(current_hour+time[index], current_min, index+1, depth-1, res)
			}
		}
	}
	return
}

func readBinaryWatch(turnedOn int) []string {
	res := []string{}
	foo(0, 0, 0, turnedOn, &res)
	return res
}

func main() {
	res := readBinaryWatch(9)
	fmt.Println(res)
}
