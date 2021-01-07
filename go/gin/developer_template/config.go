package main

import (
	"fmt"
	"github.com/BurntSushi/toml"
	"log"
)

var Config CommConfig

func LoadConfig(fpath string) {
	_, err := toml.DecodeFile(fpath, &Config)
	if err != nil {
		log.Fatalf("load config error, err=%v", err)
	}

	return
}

type CommConfig struct {
	Server ServerConfig `toml:"server"`
	DB     DbConfig     `toml:"database"`
	Log    LogConfig    `toml:"log"`
}

type ServerConfig struct {
	Port int    `toml:"port"`
	Env  string `toml:"env"` //production/test, 不填为时空,应当作正式环境
}

type DbConfig struct {
	Host     string `toml:"host"`
	Port     int    `toml:"port"`
	User     string `toml:"user"`
	Password string `toml:"password"`
	DBName   string `toml:"dbname"`
	ConnNum  int    `toml:"conn_num"`
	CharSet  string `toml:"charset"`
}

type LogConfig struct {
	LogPath  string `toml:"logpath"`
	LogName  string `toml:"logname"`
	LogLevel int    `toml:"loglevel"`
	MaxSize  int64  `toml:"maxsize"`
	MaxNum   int    `toml:"maxnum"`
}

func (p *DbConfig) ToConfigString() string {
	charset := "utf8"
	if p.CharSet != "" {
		charset = p.CharSet
	}
	return fmt.Sprintf("%s:%s@tcp(%s:%d)/%s?charset=%s&parseTime=true&loc=Local", p.User, p.Password, p.Host, p.Port, p.DBName, charset)
}
