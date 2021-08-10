package simplemath

import (
	"fmt"
	"math"
)

// Sqrt /** 平方根
func Sqrt(a int) int {
	fmt.Println("Sqrt a: ", a)
	v := math.Sqrt(float64(a))
	fmt.Println("Sqrt v: ", v)
	return int(v)
}
