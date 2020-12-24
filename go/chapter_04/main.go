package main

import "fmt"

func reverse(arr *[5]int) {
  for i, j := 0, len(arr) - 1; i < j; i, j = i + 1, j - 1 {
    arr[i], arr[j] = arr[j], arr[i]
  }
}

func rotate(s []int, n int) {
  n %= len(s)
  tmp := append(s, s[:n]...)
  copy(s, tmp[n:])
}

func empty_repeat(arr []string) []string {
  for i := 0; i < len(arr) - 1; {
    if (arr[i] == arr[i + 1]) {
      copy(arr[i:], arr[i + 1:])
      arr = arr[:len(arr) - 1]
    } else {
      i++;
    }
  }
  return arr
}

func main() {
  // exercise 4.3
  // arr := [...]int{0, 1, 2, 3, 4}
  // fmt.Println(arr)
  // reverse(&arr)
  // fmt.Println(arr)

  // exercise 4.4
  // arr := []int{0, 1, 2, 3, 4}
  // rotate(arr, 2)
  // fmt.Println(arr)

  // exercise 4.5
  // [a b b b c b]
  // [a b b c b b]
  // [a b b c b]
  // [a b c b b]
  // [a b c b]
  arr := []string{"a", "b", "b", "b", "c", "b"}
  arr = empty_repeat(arr[:])
  fmt.Println(arr)
}
