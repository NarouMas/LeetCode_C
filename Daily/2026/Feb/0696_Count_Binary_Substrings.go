package main

func countBinarySubstrings(s string) int {
	res, count := 0, 1
	stat := s[0]
	for i := 1; i < len(s); {
		if s[i] == stat {
			count++
			i++
		} else {
			j := 0
			for ; i+j < len(s) && s[i+j] != stat; j++ {

			}
			res += min(count, j)
			stat = s[i]
			count = j
			i = i + j
		}
	}
	return res
}

func main() {
	s := "00110011"
	countBinarySubstrings(s)
}
