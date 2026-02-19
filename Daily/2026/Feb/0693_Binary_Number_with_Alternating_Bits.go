package main

func hasAlternatingBits(n int) bool {
	stat := n & 1
	n = n >> 1
	for n > 0 {
		if stat == n&1 {
			return false
		}
		n = n >> 1
		stat = stat ^ 1
	}
	return true
}
