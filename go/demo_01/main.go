package main

import (
	"fmt"
)

type base struct {
	age uint
}

func foo(arr []base) {
	arr[0].age = 256

	fmt.Println(&arr[0].age)
}

func main() {
	b := base{age:1024}
	fmt.Println(b.age)

	arr := []base{b}
	fmt.Println(&arr[0].age)

	foo(arr)

	fmt.Println(b.age)
}
