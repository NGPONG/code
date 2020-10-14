package com.learnjava;

import com.learnjava.entity.User;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import java.util.ArrayList;
import java.util.List;
import java.sql.PreparedStatement;


@Component
public class DatabaseInitializer {
  final Logger logger = LoggerFactory.getLogger(getClass());

  @Autowired
  JdbcTemplate jdbc_template;

  @PostConstruct
  private void init() {
    try {
      var res = jdbc_template.execute("select * from users", (PreparedStatement ps) -> {
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

      if(res == null) {
        throw new RuntimeException("MSSQL Driver init error");
      }

      logger.info("DataBase init ok, ROWNUMBER = " + res.stream().count());
    } catch (Exception e) {
      logger.error(e.getMessage());
    }
  }
}
