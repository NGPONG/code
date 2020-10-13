package org.example.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

@Component
public class user_service {
  @Autowired
  JdbcTemplate jdbc_template;

  public List<user> get_user_info() {
      return jdbc_template.execute("select * from users", (PreparedStatement ps) -> {
        try (var rs = ps.executeQuery()) {
          List<user> lit = new ArrayList<>();

          while (rs.next()) {
            var usr = new user(rs.getLong("Id"),
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
