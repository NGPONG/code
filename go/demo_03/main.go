package main

import (
	"bytes"
	"crypto/tls"
	"encoding/json"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"mime/multipart"
	"net"
	"net/http"
	"net/url"
	"os"
	"strings"
	"time"
)

type ImageUploadResponse struct {
	ErrCode int	   `json:"errcode"`
	ErrMsg  string `json:"errmsg"`
	Url string `json:"url"`
}

func new_http_cli() (*http.Client) {
	proxy := func(_ *http.Request) (*url.URL, error) {
		return url.Parse("http://127.0.0.1:8866")
	}

	return &http.Client {
		Transport: &http.Transport{
			Proxy: proxy,
			DialContext: (&net.Dialer{
				Timeout:   time.Duration(300) * time.Second,
				KeepAlive: 30 * time.Second,
			}).DialContext,
			MaxIdleConns:        100,
			MaxIdleConnsPerHost: 100,
			IdleConnTimeout:     time.Duration(300) * time.Second,
			TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
		},
	}
}

func foo() {
	buf := bytes.NewBuffer(nil)
	result := &ImageUploadResponse{}

	file, err := os.Open("./abcasda.png")
	if err != nil {
		log.Fatal(err)
	}

	_, err = io.Copy(buf, file)
	if err != nil {
		log.Fatal(err)
	}

	boundary := "acebdf13572468"
	splitc := "---------------------------"

	fileBuffer := buf.Bytes()

	content := splitc + boundary + "\n"
	content = content + "Content-Disposition: form-data; name=\"media\"; filename=\"mypic.png\";\n"
	content = content + "Content-Type: image/png\n"
	content = content + "Content-Length: " + fmt.Sprintf("%d", len(fileBuffer)) + "\n\n"
	content = content + string(fileBuffer) + "\n"
	content = content + splitc + boundary + "--"

	req, err := http.NewRequest("POST", "https://qyapi.weixin.qq.com/cgi-bin/media/uploadimg?access_token=ZI26-iyBM5cRqLIR42KYYD23fmdBcPIGiF7d6ODYOGu_d0gaIYaKY-DWPT8GsBfgqDSHphjr1WKoeQie10Vthf5gGnu0KRn0NDEOCbIWl6XC2TDZ5YX7Sk98UNfbCJqg7DRNyBLWx70cY9MrtR0NTIUAEyLhniNp6eBWLePQ6WdGDa-XIoHvfc9zkJoiCcv_vYz21WsBTMaUM58zqJMcxg", strings.NewReader(content))	
	if err != nil {
		log.Fatal(err)
	}
	req.Header.Set("Content-Type", "multipart/form-data; boundary=" + boundary)

	http_cli := new_http_cli()
	resp, err := http_cli.Do(req)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	respBody, err := ioutil.ReadAll(resp.Body)
	if err := json.Unmarshal([]byte(respBody), result); err != nil {
		log.Fatal(err)
	}

	log.Printf("%v", result)
	
}

func foo_2() {
	result := &ImageUploadResponse{}
	bodyBuf := &bytes.Buffer{}
	bodyWrite := multipart.NewWriter(bodyBuf)

	file, err := os.Open("./abcasda.png")
	defer file.Close()
	if err != nil {
		log.Fatal(err)
	}
	fileWrite, err := bodyWrite.CreateFormFile("file", "123.png")
	
	_,err = io.Copy(fileWrite,file)
	if err != nil {
		log.Fatal(err)
	}

	contentType := bodyWrite.FormDataContentType()
	bodyWrite.Close() 
	request, err := http.NewRequest("POST", "https://qyapi.weixin.qq.com/cgi-bin/media/uploadimg?access_token=ZI26-iyBM5cRqLIR42KYYD23fmdBcPIGiF7d6ODYOGu_d0gaIYaKY-DWPT8GsBfgqDSHphjr1WKoeQie10Vthf5gGnu0KRn0NDEOCbIWl6XC2TDZ5YX7Sk98UNfbCJqg7DRNyBLWx70cY9MrtR0NTIUAEyLhniNp6eBWLePQ6WdGDa-XIoHvfc9zkJoiCcv_vYz21WsBTMaUM58zqJMcxg", bodyBuf)
	if err != nil {
		fmt.Println("http newrequest error",err)
		return
	}
	
	request.Header.Set("Content-Type", contentType)

	http_cli := new_http_cli()
	resp, err := http_cli.Do(request)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	respBody, err := ioutil.ReadAll(resp.Body)
	if err := json.Unmarshal([]byte(respBody), result); err != nil {
		log.Fatal(err)
	}

	log.Printf("%v", result)
}

func foo_3() {
	d := time.Now()
	str := d.Format("2006-01-02")

	fmt.Println(str)
}

func main() {
	foo_3()
}
