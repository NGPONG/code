package main

import (
	"fmt"
)

func foo() func() {
  fmt.Println("hello,world")
  return func() {
    fmt.Println("hello,world2")
  }
}

func f() {
  defer foo()()
  fmt.Println("NGPONG")
}

func main() {
  f();
}
