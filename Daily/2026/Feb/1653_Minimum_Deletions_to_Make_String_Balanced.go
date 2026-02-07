package make

func minimumDeletions(s string) int {
	res, b := 0, 0
	for _, e := range s {
		if e == 'b' {
			b++
		} else if b > 0 {
			res++
			b--
		}
	}
	return res
}
