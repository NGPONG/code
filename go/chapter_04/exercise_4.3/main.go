package main

import "fmt"

func reverse(arr *[5]int) {
  for i, j := 0, len(arr) - 1; i < j; i, j = i + 1, j - 1 {
    arr[i], arr[j] = arr[j], arr[i]
  }
}

func main() {
  arr := [...]int{0, 1, 2, 3, 4}
  fmt.Println(arr)
  reverse(&arr)
  fmt.Println(arr)
}
