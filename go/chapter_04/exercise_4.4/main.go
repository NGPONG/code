package main

import "fmt"

func rotate(s []int, n int) {
  n %= len(s)
  tmp := append(s, s[:n]...)
  copy(s, tmp[n:])
}

func main() {
  arr := []int{0, 1, 2, 3, 4}
  rotate(arr, 2)
  fmt.Println(arr)
}
