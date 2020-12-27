package main

import (
	"fmt"
)

func expand(s string, f func(string) string) string {
	var ret string = ""
	var tmp string = ""

	str_len := len(s)
	for i := 0; i < str_len; i++ {
		if s[i] == '$' {
			j := i + 1

			for ; j < str_len; j++ {
				if s[j] == ' ' {
					break
				}

				tmp += string(s[j])
			}

			ret += f(tmp)
			i = j - 1
			tmp = ""
		}

		ret += string(s[i])
	}

	return ret
}

func main() {
	str := "hello $,wor ld $123"

	fmt.Println(expand(str, func(s string) string {
		return "hello" + s
	}))
}
