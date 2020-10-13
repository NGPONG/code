package com.learnjava.service;

import com.learnjava.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import java.util.List;

@Component
public class UserService {
  @Autowired
  JdbcTemplate jdbc_template;

  /**
   * 模拟使用 jdbc_template 查询出来的结果，
   * 傻批 mssql 用不了，待老子装个 mysql
   */
  List<User> lit = List.of(new User(1, "pengpeng1997428@gmail.com", "Pengqi1997.0428", "NGPONG"),
          new User(2, "1917648573@qq.com", "pengqi1997428", "wupeng"),
          new User(3, "test@email.com", "123", "hello,world"));

  public List<User> GetUserInfo() {
    return lit;
  }

  public User GetUserByName(String name) {
    return lit.get(0);
  }
}
