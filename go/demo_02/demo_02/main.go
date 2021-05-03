package main

import (
	"fmt"
	"net/url"
)

func init_params_map(length int) ([]map[string]string) {
	params := make([]map[string]string, length)
	for idx, _ := range params {
		params[idx] = make(map[string]string)
	}

	return params
}

func main() {
	params := init_params_map(2)

	params[0] = make(map[string]string)
	params[0]["123"] = "qwe"
	params[0]["qwe"] = "qwe"
	params[0]["asd"] = "qwe"
	
	fmt.Println("2")

	values := url.Values{}
	for _, param := range params {
		for key, val := range param {
			values.Add(key, val)
		}
	}
	query := values.Encode()

	fmt.Println(query)
}

