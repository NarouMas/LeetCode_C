package main


func reverseBits(n int) int {
    res := 0
	base := 1 << 30
	n = n >> 1
	for n > 0 {
		if n & 1 == 1 {
			res += base
		}
		n = n >> 1
		base = base >> 1
	}
	return res
}