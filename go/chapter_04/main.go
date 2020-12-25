package main

import (
	"encoding/json"
	"fmt"
	"log"
)

type Person struct {
  Id   uint32 `json:"id"`
  Name string `json:"name"`
}

func main() {
  pers := [...]Person{
    { Id : 0, Name : "a" },
    { Id : 1, Name : "b" },
  }

  fmt.Println(pers)

  if data, err := json.MarshalIndent(pers, "", "  "); err == nil {
    fmt.Printf("%s\n", data)
  } else {
    log.Fatal("JSON MARSHALING FAILD")
  }
}
