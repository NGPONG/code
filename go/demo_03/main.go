package main

import (
	"encoding/json"
	"log"
)

type Text struct {
	Content string `json:"content" form:"content"`
}

type Image struct {
	MediaId string `json:"media_id" form:"media_id"`
	PicUrl string `json:"pic_url" form:"pic_url"`
}

func foo(data interface{}) {
	buffer, err := json.Marshal(data)
	if err != nil {
		log.Printf("%v", err)
	}

	log.Printf("%s", string(buffer))
}

func main() {
	m := make(map[string]interface{})
	m["welcome_code"] = "CALLBACK_CODE"

	m["text"] = Text {
		Content: "hello,world",
	}
	m["image"] = Image {
		MediaId: "123",
		PicUrl: "google.com",
	}

	foo(m)
}
