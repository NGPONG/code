package main

import (
	"log"
	"net/http"
)


func main() {
	httpClient := &http.Client {
			Transport: &http.Transport {
				Proxy: http.ProxyFromEnvironment,
			},
	}

	req, err := http.NewRequest("GET", "https://tgl-images-1254960240.cos.ap-guangzhou.myqcloud.com/sy/qmqj2/ingame/images/20210401/2440737335_1617267884532.png", nil)	
	if err != nil {
		log.Printf("Create http request err: %v", err)
		return
	}
		
    resp, err := httpClient.Do(req)
	if err != nil {
		log.Printf("Do http request err: %v", err)
		return
	}

	if resp.StatusCode == http.StatusForbidden || resp.StatusCode == http.StatusNotFound {
		log.Printf("Dirty picture detected, url")
		return
	}

    resp.Body.Close()
}
