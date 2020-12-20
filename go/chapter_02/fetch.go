package main

import (
	"fmt"
	"io"
	// "io/ioutil"
	"net/http"
	"os"
)

func main() {
  for _, url := range os.Args[1:] {
    resp, err := http.Get(url)
    if err != nil {
      fmt.Fprintf(os.Stderr, "%v\n", err)
      os.Exit(1)
    }
    length, err := io.Copy(os.Stdout, resp.Body)
    resp.Body.Close()
    if err != nil {
      fmt.Fprintf(os.Stderr, "%v\n", err)
      os.Exit(1)
    }
    fmt.Printf("length = %d\n", length)
    fmt.Printf("http status = %s\n", resp.Status)
  }
}
