package main

import (
    "log"
    "github.com/gin-gonic/gin"
)

type Person struct {
	Name     string    `json:"name"`
    Address  string    `json:"address"`
}

func main() {
    route := gin.Default()
    route.POST("/foo", startPage)
    route.Run(":8889")
}

func startPage(c *gin.Context) {
    var person Person
    if c.ShouldBind(&person) == nil {
		log.Println(person.Name)
        log.Println(person.Address)
    }

    c.String(200, "Success")
}
