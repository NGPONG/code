package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Printf("[%d] %s\n", 0, os.Args[0])	

	for idx, val := range os.Args {
		if idx == 0 {
			continue
		}

		fmt.Printf("[%d] %s\n", idx, val)
	}
}
