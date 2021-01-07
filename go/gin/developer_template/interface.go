package main

import (
	"github.com/gin-gonic/gin"
	"log"
	"net/http"
	"strconv"
)

func sendSms(c *gin.Context) {
	num, _ := strconv.Atoi(c.Query("num"))

	for i := 0; i < num; i++ {
		log.Printf("hello world")
	}
	c.JSON(http.StatusOK, gin.H{
		"code": 0,
		"msg":  "success",
	})
}

func queryUser(c *gin.Context) {
	openid := c.Query("openid")

	if openid == "" {
		renderErr(c, 1000, "param error")
		return
	}
	user, err := QueryUserInfo(openid)
	if err != nil {
		renderErr(c, 1001, "QueryUserInfo failed")
		return
	}
	renderSuccess(c, user)

}
