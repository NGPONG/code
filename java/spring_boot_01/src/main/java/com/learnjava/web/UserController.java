package com.learnjava.web;

import com.learnjava.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.sql.PreparedStatement;
import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/api/users")
public class UserController {
  @Autowired
  JdbcTemplate jdbc_template;

  @GetMapping("/")
  public List<User> GetAllUserInfo() {
    return jdbc_template.execute("select * from users", (PreparedStatement ps) -> {
      try (var rs = ps.executeQuery()) {
        List<User> lit = new ArrayList<>();

        while (rs.next()) {
          var usr = new User(rs.getLong("Id"),
                  rs.getString("email"),
                  rs.getString("password"),
                  rs.getString("name"));
          lit.add(usr);
        }
        return lit;
      }
    });
  }

  @GetMapping("/{name}")
  public List<User> GetUserByName(@PathVariable("name") String name) {
    return jdbc_template.execute("select * from users", (PreparedStatement ps) -> {
      try (var rs = ps.executeQuery()) {
        List<User> lit = new ArrayList<>();

        while (rs.next()) {
          var usr = new User(rs.getLong("Id"),
                  rs.getString("email"),
                  rs.getString("password"),
                  rs.getString("name"));
          lit.add(usr);
        }
        return lit;
      }
    });
  }
}
