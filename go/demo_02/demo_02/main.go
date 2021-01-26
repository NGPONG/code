package main

import (
	"fmt"
	"github.com/spf13/pflag"
)

var (
	env = pflag.StringP("env", "e", "", "Please input env.")
)

func main() {
	pflag.Parse()

	fmt.Println(*env)
}

