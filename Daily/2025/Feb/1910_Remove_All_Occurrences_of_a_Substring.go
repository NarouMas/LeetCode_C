package main
import (
	"fmt"
)

func removeOccurrences(s string, part string) string {
    arr := make([]byte, len(s))
	index := 0
	for i := 0; i < len(s); i++ {
		arr[index] = s[i]
		index++
		if index < len(part) {
			continue
		}
		if string(arr[index - len(part):index]) == part {
			index -= len(part)
		}
	}
	return string(arr[0:index])
}

func main(){
	s := "daabcbaabcbc"
	part := "abc"
	fmt.Println(removeOccurrences(s, part))
}