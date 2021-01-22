package main

import (
	"fmt"
	"net/http"

	"github.com/gin-gonic/gin"
)

const (
	configFile string = "./cfg/config.toml"
)

func initRouter(r *gin.Engine) {
	route := r.Group("/base")
	route.GET("/sms", sendSms)
	route.GET("/user", queryUser)
	route.GET("/test", test)
}

func main() {
	LoadConfig(configFile)
	DbInit()
	r := gin.Default()
	initRouter(r)
	r.Run(":9099")
}

func renderSuccess(c *gin.Context, data interface{}) {
	c.JSON(http.StatusOK, gin.H{
		"code": 0,
		"data": data,
	})
}

func test(c *gin.Context) {
	queryStr := c.Request.URL.RawQuery
	fmt.Println(queryStr)
	fmt.Println(c.Query("hello"))

	queryStr = ""
	queryStr = c.Request.URL.RawQuery
	fmt.Println(queryStr)
	fmt.Println(c.Query("hello"))

	c.JSON(http.StatusOK, gin.H{
		"code": 0,
	})
}


func renderErr(c *gin.Context, code int, msg string) {
	c.JSON(http.StatusOK, gin.H{
		"code": code,
		"msg":  msg,
	})
}
