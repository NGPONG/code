package main

import "fmt"

type person struct {
  id    int
  name  string
}

func main() {
  var per person
  per.id = 10
  per.name = "hello,world"
}
