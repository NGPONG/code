package main

import (
  "bufio"
  "crypto/sha256"
  "crypto/sha512"
  "flag"
  "fmt"
  "os"
)

var f = flag.String("flag", "sha256", "flag = sha256 | sha384 | sha512")

func main() {
  flag.Parse()

  sc_input := bufio.NewScanner(os.Stdin)
  if sc_input.Scan() {
    bytes := sc_input.Bytes()
    switch *f {
      case "sha256":
      fmt.Println(sha256.Sum256(bytes))
      case "sha384":
      fmt.Println(sha512.Sum384(bytes))
      case "sha512":
      fmt.Println(sha512.Sum512(bytes))
    }
  }
}
