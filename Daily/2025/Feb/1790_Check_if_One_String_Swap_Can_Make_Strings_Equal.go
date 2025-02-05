package main
import (
	"fmt"
)

func areAlmostEqual(s1 string, s2 string) bool {
    different_count := 0
	var a, b int
	for i := 0; i < len(s1); i++ {
		if s1[i] != s2[i] {
			if different_count == 2 {
				return false
			}
			different_count += 1
			if different_count == 1 {
				a = i
			} else {
				b = i
			}
		}
	}
	if s1[a] == s2[b] && s1[b] == s2[a] {
		return true
	}
	return false
}

func main(){
	s1 := "abcd"
	s2 := "acbd"
	fmt.Println(areAlmostEqual(s1, s2))
}