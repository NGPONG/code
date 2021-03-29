package main

import (
	"crypto/sha1"
	"encoding/hex"
	"fmt"
	"io"
)

func main() {
	str := "www.5lmh.com"

	//方法一    
	data := []byte(str)
	has := sha1.Sum(data)
	shastr1 := fmt.Sprintf("%x", has) //将[]byte转成16进制    
	fmt.Println(shastr1)

	//方法二    
	w := sha1.New()
	io.WriteString(w, str) //将str写入到w中    
	bw := w.Sum(nil) //w.Sum(nil)将w的hash转成[]byte格式    
	// shastr2 := fmt.Sprintf("%x", bw)    //将 bw 转成字符串    
	shastr2 := hex.EncodeToString(bw) //将 bw 转成字符串    
	fmt.Println(shastr2)
}
