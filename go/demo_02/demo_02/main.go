package main

import (
	"fmt"
	"time"
)

func main() {
	dt, err := time.Parse("2006-01-02 15:04", "2018-01-20 04:35")
	if err != nil {
		fmt.Println(err)
	}
	

	fmt.Println(dt)
}

