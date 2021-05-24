package main

import (
	"fmt"
	"strings"
)

type yybtaskconditionRespData struct {
	Status int   `json:"status"`
	UserId int64 `json:"userId"`
}
type yybtaskconditionResp struct {
	Result	   int    `json:"result"`
	ReturnCode int    `json:"returnCode"`
	ReturnMsg  string `json:"returnMsg"`
	Data []yybtaskconditionRespData `json:"data"`
}

func main() {
	strSource := "{\"result\":1,\"returnCode\":0,\"returnMsg\":\"\u7528\u6237\u4e0d\u5b58\u5728\",\"time\":\"3.8\",\"data\":[]}"
	contain := strings.Contains(strSource, "\"returnCode\":0")
	fmt.Println(contain)
}
