package main

import "fmt"

func empty_repeat(arr []string) []string {
  for i := 0; i < len(arr) - 1; {
    if arr[i] == arr[i + 1] {
      copy(arr[i:], arr[i + 1:])
      arr = arr[:len(arr) - 1]
    } else {
      i++
    }
  }

  return arr
}

func main() {
  // [a b b b c b]
  // [a b b c b b]
  // [a b b c b]
  // [a b c b b]
  // [a b c b]
  arr := []string{"a", "b", "b", "b", "c", "b"}
  arr = empty_repeat(arr[:])
  fmt.Println(arr)
}
