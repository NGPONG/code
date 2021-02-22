package main

import (
	"fmt"
	"log"
	"time"

	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

const (
	AWARD_RULES_ONLY_ONE = 0 // 满足领奖条件后，仅可领取一次a

	AWARD_STATUS_ALL					= 0 // 全部
	AWARD_STATUS_DEAD_LINE  			= 1 // 已过期
	AWARD_STATUS_EFFECTICVE_ALMOST_DONE = 2 // 生效中，即将领完
	AWARD_STATUS_DONED				    = 3 // 已领完
	AWARD_STATUS_EFFECTICVE 		    = 4 // 生效中
	AWARD_STATUS_DELETED    		    = 5 // 已删除
)


type ActivityResponseListItem struct {
	ID			  uint	    `gorm:"column:id" json:"id"`						 // 序号
	ActivityName  string    `gorm:"column:activity_name" json:"activity_name"`   // 活动奖励名
	RewardRule    string    `gorm:"column:reward_rule" json:"reward_rule"`       // AMS单号
	ReceivedNum   string    `gorm:"column:received_num" json:"received_num"`     // 总发放数量/实际发放数量
	Operators     string    `gorm:"column:operators" json:"operators"`           // 最后操作人
	RewardAddress string    `gorm:"column:reward_address" json:"reward_address"` // 奖励链接
	ActRewardNum  int	    `gorm:"column:act_reward_num" json:"act_reward_num"` // 实际发放数量
	RewardNum	  int       `gorm:"column:reward_num" json:"reward_num"`		 // 总发放数量
	Updated       time.Time `gorm:"column:updated" json:"updated"`				 // 最后更新时间
	Status        int		`json:"status"`										 // 状态

	ActivityEnd   time.Time `gorm:"column:activity_end"`
	IsDeleted	  bool      `gorm:"column:is_deleted"`
}

func fillQueryResponseStatus(ret []ActivityResponseListItem) ([]ActivityResponseListItem) {
	for idx, _ := range ret {
		if ret[idx].IsDeleted {
			ret[idx].Status = AWARD_STATUS_DELETED
		} else if time.Now().Before(ret[idx].ActivityEnd) {
			ret[idx].Status = AWARD_STATUS_DEAD_LINE
		} else {
			div := float64(ret[idx].ActRewardNum) / float64(ret[idx].RewardNum)
			if div < 0.9 {
				ret[idx].Status = AWARD_STATUS_EFFECTICVE	
			} else if div >= 0.9 {
				ret[idx].Status = AWARD_STATUS_EFFECTICVE_ALMOST_DONE
			} else if div == 1 {
				ret[idx].Status = AWARD_STATUS_DONED
			}
		}
	}


	return ret
}


func main() {
    db, err := gorm.Open("mysql", "root:Pengqi1997.0428@tcp(192.168.255.10:3306)/ingame_qywechat_activity?charset=utf8&parseTime=true")
	db.LogMode(true)
	defer db.Close()
    if err != nil {
        fmt.Printf("mysql connect error %v", err)
    }

	var ret []ActivityResponseListItem
	var total int


	query := db.Table("ingame_qywechat_activity.activity")
	query = query.Joins("left join ingame_qywechat_activity.user_reward on ingame_qywechat_activity.user_reward.activity_id = ingame_qywechat_activity.activity.id")

	query = query.Having("count(ingame_qywechat_activity.user_reward.id) / ingame_qywechat_activity.activity.reward_num < 0.9")
	query = query.Where("is_deleted = ?", false)
	query = query.Select("ingame_qywechat_activity.activity.id, activity_name, reward_address, reward_rule, reward_num, ingame_qywechat_activity.activity.updator as operators, concat(count(ingame_qywechat_activity.user_reward.id), ' / ', reward_num) as received_num, count(ingame_qywechat_activity.user_reward.id) as act_reward_num, ingame_qywechat_activity.activity.updated, ingame_qywechat_activity.activity.is_deleted")
	query = query.Group("ingame_qywechat_activity.activity.id")
	query = query.Order("ingame_qywechat_activity.activity.created desc")

	// Complute total count.
	if err = query.Count(&total).Error; err != nil {
		log.Printf("%v\n", err)
		return
	}
	log.Printf("total: %d\n", total)

	if err = query.Offset(0).Limit(10).Find(&ret).Error; err != nil {
		log.Printf("%v\n", err)
		return
	}

	ret = fillQueryResponseStatus(ret)

	for _, entity := range ret {
		log.Printf("id: %d, is_deleted: %t, activity_name: %s, status: %d, received_num: %s\n", entity.ID, entity.IsDeleted ,entity.ActivityName, entity.Status, entity.ReceivedNum)
	}
}
