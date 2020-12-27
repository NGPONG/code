package main

import (
	"fmt"
	"net/http"
	"strings"

	"golang.org/x/net/html"
)

var (
  image_count int    = 0
  dic map[string]int = make(map[string]int)
)

func countWordsAndImages(node *html.Node) {
  if node.Type == html.TextNode {
    words := strings.Fields(node.Data)
    for _, word := range words {
      dic[word]++
    }
  } else if node.Type == html.ElementNode && node.Data == "img" {
    image_count++
  }

  for child := node.FirstChild; child != nil; child = child.NextSibling {
    countWordsAndImages(child)
  }
}

func foo() error {
  resp, err := http.Get("https://www.sulinehk.com")
  if err != nil {
    return fmt.Errorf("parsing HTML: %s", err)
  }
  defer resp.Body.Close()

  doc, err := html.Parse(resp.Body)
  if err != nil {
    return fmt.Errorf("parsing HTML: %s", err)
  }

  countWordsAndImages(doc)

  for key, val := range dic {
    fmt.Printf("[%s] %d\n", key, val)
  }

  fmt.Println(image_count)

  return nil
}

func main() {
  foo()
}
