package main

import (
	"fmt"
	"crypto/sha256"
	"time"
)

func main() {
	h := sha256.New()

	for i := 0; i < 10; i++ {
		h.Write([]byte(fmt.Sprintf("%d", time.Now().UnixNano())))
		bs := h.Sum(nil)
		h.Reset()
		
		res := fmt.Sprintf("%x", bs)
		fmt.Println(len(res))
		fmt.Printf("%s\n", res)
	}
}
