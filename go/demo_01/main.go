package main

import (
	_ "github.com/jinzhu/gorm/dialects/mysql"
    "github.com/jinzhu/gorm"
	"fmt"
)

type ActivityResponseListItem struct {
	ID			  uint	 `gorm:"column:id" json:"id"`						  // 序号
	ActivityName  string `gorm:"column:activity_name" json:"activity_name"`   // 活动奖励名
	RewardRule    string `gorm:"column:reward_rule" json:"reward_rule"`       // AMS单号
	ReceivedNum   string `gorm:"column:received_num" json:"received_num"`     // 总发放数量/实际发放数量
	Operators     string `gorm:"column:operators" json:"operators"`           // 最后操作人
	RewardAddress string `gorm:"column:reward_address" json:"reward_address"` // 奖励链接
	ActRewardNum  int	 `gorm:"column:act_reward_num" json:"act_reward_num"` // 实际发放数量
	RewardNum	  int    `gorm:"column:reward_num" json:"reward_num"`		  // 总发放数量
}

func main() {
    db, err := gorm.Open("mysql", "root:Pengqi1997.0428@tcp(192.168.255.10:3306)/ingame_qywechat_activity?charset=utf8")
	db.LogMode(true)
	defer db.Close()
    if err != nil {
        fmt.Printf("mysql connect error %v", err)
    }

	var ret []ActivityResponseListItem

	query := db.Table("ingame_qywechat_activity.activity")
	query = query.Joins("left join ingame_qywechat_activity.user_reward on ingame_qywechat_activity.user_reward.activity_id = ingame_qywechat_activity.activity.id")
	query = query.Select("ingame_qywechat_activity.activity.id, activity_name, reward_address, reward_rule, reward_num, ingame_qywechat_activity.activity.updator as operators, concat(count(ingame_qywechat_activity.user_reward.id), ' / ', reward_num) as received_num, count(ingame_qywechat_activity.user_reward.id) as act_reward_num")
	query = query.Group("ingame_qywechat_activity.activity.id")
	query = query.Where("game_id = ?", "lol")
	query = query.Order("ingame_qywechat_activity.activity.created desc")

	query.Offset(1).Limit(1).Find(&ret)

	fmt.Println(ret)
}
