package main

import (
	"encoding/json"
	"fmt"
)


type MyStruct struct {
	Id int `json:"id"`
	Name string `json:"name"`
}


func main() {
	var str string = "[{\"id\":1041,\"name\":\"鸿图之友\"}, {\"id\":2,\"name\":\"\"}]";

	data := []byte(str)
	
	ret := []struct{
		Id int;
		Name string
	}{}

	// ret := []MyStruct{}

	// var ret []map[string]interface{}

	err := json.Unmarshal(data, &ret)
	if err != nil {
		fmt.Printf("error %v\n", err)
	}

	fmt.Printf("len = %d\n", len(ret))
	fmt.Printf("%v\n", ret)
}
