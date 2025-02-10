package main
import (
	"fmt"
)

func clearDigits(s string) string {
    arr := make([]byte, len(s))
	index := 0
	for i := 0; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			index--
		} else {
			arr[index] = s[i]
			index++
		}
	}
	result := string(arr[:index])

	return result
}

func main(){
	s := "f3e5rrf3wdaw12s"
	fmt.Println(clearDigits(s))
}