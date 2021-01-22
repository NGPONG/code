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

	query := db.Table("users")
 	query = query.Offset((page_idx - 1) * page_size).Limit(page_size)
	query = query.Raw(`select id, username, ` + "password, now() as dt " + `from ` + "users where id in (?,?)", 1, 10)
	query = query.Order("`id` asc")
	query.Find(&ret)

	fmt.Println(ret)
}
