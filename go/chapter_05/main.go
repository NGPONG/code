package main

import (
	"fmt"
	"os"
	"runtime"
	"time"
)

type Person struct {
	age int
	name string
}

func (per *Person) per_func(idx int) {
	fmt.Println(idx)
	fmt.Println(per.age)
	fmt.Println(per.name)
}

func trace() func() {
	start := time.Now()

	return func() {
		fmt.Println(time.Since(start))
	}
}

func double(x int, y int) (ret int) {
	defer fmt.Println(&ret) //func() { fmt.Printf("%d\n", ret) }()
	fmt.Println(&ret)
	return x * y
}

func foo() {
	defer trace()()
	fmt.Println("hello,world")
}

func recover_foo() {
	defer fmt.Println("hello,world")

	defer func() {
		if p := recover(); p != nil {
			buf := [4096]byte{0}
			n := runtime.Stack(buf[:], false)
			os.Stdout.Write(buf[:n])
		}
	}()

	panic("hello,world")
}

func person_foo() {
	idx := 1024

	per := Person{}
	defer per.per_func(idx)
	
	per.age = 10
	per.name = "NGPONG"
}

func (i *Person) int_foo() {
	fmt.Println(i.age)
	fmt.Println(i.name)
}

func main() {
	// foo();

	// recover_foo()
	// fmt.Println("hello,world")

	// person_foo()


	per := Person{}
	per.age = 10
	per.name = "hello,world"

	per.int_foo()
	(&per).int_foo()
}
