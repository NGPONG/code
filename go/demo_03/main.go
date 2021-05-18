package main

import (
	"fmt"
	"math/rand"
	"time"
)

func foo_3() {
	timeStamp := time.Now().Unix()
	fmt.Println(timeStamp)

	rander := rand.Intn(99999-10000) + 10000
	fmt.Println(rander)
}

func main() {
	foo_3()
}
