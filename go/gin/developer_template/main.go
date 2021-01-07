package main

import (
	"github.com/gin-gonic/gin"
	"net/http"
)

const (
	configFile string = "./cfg/config.toml"
)

func initRouter(r *gin.Engine) {
	route := r.Group("/base")
	route.GET("/sms", sendSms)
	route.GET("/user", queryUser)
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

func renderErr(c *gin.Context, code int, msg string) {
	c.JSON(http.StatusOK, gin.H{
		"code": code,
		"msg":  msg,
	})
}
