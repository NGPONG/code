package main

import (
	"fmt"
)

func appendInt(src []int, val int) []int {
  var tmp []int
  zlen := len(src) + 1
  if zlen <= cap(src) {
    tmp = src[:zlen]
  } else {
    zcap := zlen
    if zcap < 2 * len(src) {
      zcap = 2 * len(src)
    }
    tmp = make([]int, zlen, zcap)
    copy(tmp, src)
  }
  tmp[len(src)] = val

  fmt.Printf("len = %d, cap = %d ", len(tmp), cap(tmp))

  return tmp
}

func non_empty(src []string) []string {
  out := src[:0]
  for _, s := range src {
    if (s != "") {
      out = append(out, s)
    }
  }
  return out
}

func main() {
  data := []string{"hello", "", "world", ""}
  fmt.Println(data)
  new_data := non_empty(data)
  fmt.Println(new_data)
}
