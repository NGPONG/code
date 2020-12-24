package main

import "crypto/sha256"
import "fmt"

func main() {
  s_1 := sha256.Sum256([]byte("x"))
  s_2 := sha256.Sum256([]byte("x"))

  fmt.Println(sha256_diff_bit_count(&s_1, &s_2))
}

func sha256_diff_bit_count(s_1, s_2 *[32]byte) int {
  var count int = 0
  for i := 0; i < 32; i++ {
    count += diff_bit_count(s_1[i], s_2[i])
  }
  return count
}

func diff_bit_count(b_1, b_2 byte) int {
  var count int = 0
  for i := uint(0); i < 8; i++ {
    mask := byte(1 << i)
    if (b_1 & mask) != (b_2 & mask) {
      count++
    }
  }
  return count
}
