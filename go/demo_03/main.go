package main

import (
	"log"
	"time"
	"github.com/gin-gonic/gin"
)

type ActivityEntityCreate struct {
	ActivityName   string	 `json:"activity_name" form:"activity_name" binding:"required"`		// 活动奖励名
	ActivityStart  time.Time `json:"activity_start" form:"activity_start" binding:"required"`	// 可领奖时间开始
	ActivityEnd    time.Time `json:"activity_end" form:"activity_end" binding:"required"`		// 可领奖时间结束
	RewardRule     string 	 `json:"reward_rule" form:"reward_rule" binding:"required"`			// AMS单号
	RewardPicUrl   string 	 `json:"reward_pic_url" form:"reward_pic_url" binding:"required"`	// 奖励页面底图链接
	RewardAddress  string	 `json:"reward_address" form:"reward_address" binding:"required"`   // 活动链接
	RewardDocument string 	 `json:"reward_document" form:"reward_document" binding:"required"` // 奖励文案
	RewardNum      int       `json:"reward_num" form:"reward_num" binding:"required"`		    // 奖品总数
	Rules		   int	     `json:"rules" form:"rules"`						// 领奖规则(0:满足领奖条件后，仅可领取一次)
}


func main() {
	r := gin.New()
	r.POST("first", test)
	r.Run(":8080")
}

func test(c *gin.Context) {
	var reqParm ActivityEntityCreate
	if err := c.ShouldBind(&reqParm); err != nil {
		log.Print(err)
		return
	}

	log.Print(reqParm)
}
