package main

import (
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
)

var db *gorm.DB

func DbInit() {
	var err error

	config := Config.DB.ToConfigString()

	db, err = gorm.Open("mysql", config)
	if err != nil {
		panic(err)
	}
	fmt.Println("Database config:", config)
}

type User struct {
	Id     int    `gorm:"column:id;primary_key" json:"id"`
	Game   string `gorm:"column:game" json:"game"`
	Bid    string `gorm:"column:bid" json:"bid"`
	Openid string `gorm:"column:openid" json:"openid"`
}

func QueryUserInfo(openid string) (*User, error) {
	var user User
	err := db.Table("user").Where("openid=?", openid).First(&user).Error
	if err != nil {
		return nil, err
	}
	return &user, nil
}
