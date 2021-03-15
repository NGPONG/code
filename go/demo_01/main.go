package main

import (
	"encoding/json"
	"fmt"
	"log"

	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type ChannelCodeGroup struct {
	gorm.Model
	GroupName		string `gorm:"column:group_name"`
	ParentGroupId	int	   `gorm:"column:parent_group_id"`
}

func main() {
    db, err := gorm.Open("mysql", "root:Pengqi1997.0428@tcp(192.168.255.10:3306)/ingame_qywechat_activity?charset=utf8&parseTime=true")
	db.LogMode(true)
	defer db.Close()
    if err != nil {
        fmt.Printf("mysql connect error %v", err)
    }

	ret := []ChannelCodeGroup{}
	query := db.Table("ingame_qywechat_activity.channel_code_group")
	if err = query.Find(&ret).Error; err != nil {
		log.Printf("%v\n", err)
		return
	}

	retMap := make(map[uint]ChannelCodeGroup)
	for _, v := range ret {
		retMap[v.ID] = v
	}

	jsonStr, _ := json.Marshal(retMap)
	fmt.Printf("%s", jsonStr)
}
