package main

import (
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

	tx := db.Begin()

	ent := ChannelCodeGroup {
		GroupName: "NGPONG",
		ParentGroupId: 1,
	}

	err = tx.Table("ingame_qywechat_activity.channel_code_group").Create(&ent).Error
	if err != nil {
		log.Printf("create err %v", err)
		tx.Rollback()
	}

	err = tx.Commit().Error
	if err != nil {
		log.Printf("create err %v", err)
	}

	log.Printf("create success!")
}
