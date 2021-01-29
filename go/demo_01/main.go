package main

import (
	_ "github.com/jinzhu/gorm/dialects/mysql"
    "github.com/jinzhu/gorm"
	"fmt"
)

type User struct {
    ID       int64  `gorm:"column:id;primary_key"` 
    Username string `gorm:"column:username"`
    Password string `gorm:"column:password"`
	Test_01  string `gorm:"column:test_01"`
}

func (User) TableName() string {
    return "users"
}

const (
	page_size = 10
	page_idx  = 1
)

func main() {
    db, err := gorm.Open("mysql", "root:Pengqi1997.0428@tcp(192.168.255.10:3306)/ngpong_test?charset=utf8")
	db.LogMode(true)
	defer db.Close()
    if err != nil {
        fmt.Printf("mysql connect error %v", err)
    }

	var ret []User

	query := db.Table("users, count(1) as num")
	query = query.Group("username")
	query = query.Where("username in (?)", "ngpong")
	query = query.Select("username, password, test_01")

	query.Find(&ret)

	fmt.Println(ret)
}
