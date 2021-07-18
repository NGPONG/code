package main

import (
	"fmt"
	"os"
)

func main() {
	var str string
	
	for i := 1; i < len(os.Args); i++ {
		str += (" " +os.Args[i])
	}

	fmt.Println(os.Args[1:])
	fmt.Println(str)
}
