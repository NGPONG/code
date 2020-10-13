package org.example;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DriverManagerDataSource;

import javax.sql.DataSource;

@Configuration
@ComponentScan
@PropertySource("jdbc.properties")
public class app_config {
  @Value("${jdbc.url}")
  String jdbc_url;
  @Value("${jdbc.username}")
  String jdbc_username;
  @Value("${jdbc.password}")
  String jdbc_password;

  @Bean
  @Qualifier("mssql_datasource")
  DataSource create_datasource() {
    DriverManagerDataSource src = new DriverManagerDataSource();
    src.setUrl(this.jdbc_url);
    src.setUsername(this.jdbc_username);
    src.setPassword(this.jdbc_password);
    src.setDriverClassName("com.microsoft.sqlserver.jdbc.SQLServerDriver");

    return src;
  }

  @Bean
  JdbcTemplate create_jdbc_template(@Autowired @Qualifier("mssql_datasource") DataSource _src) {
    return new JdbcTemplate(_src);
  }
}
