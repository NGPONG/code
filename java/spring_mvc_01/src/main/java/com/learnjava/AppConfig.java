package com.learnjava;


import com.mitchellbosecke.pebble.PebbleEngine;
import com.mitchellbosecke.pebble.loader.ServletLoader;
import com.mitchellbosecke.pebble.spring.extension.SpringExtension;
import com.mitchellbosecke.pebble.spring.servlet.PebbleViewResolver;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DriverManagerDataSource;
import org.springframework.web.servlet.ViewResolver;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import javax.servlet.ServletContext;
import javax.sql.DataSource;

@Configuration
@ComponentScan
@EnableWebMvc
@PropertySource("classpath:/jdbc.properties")
public class AppConfig {
  /* mvc_core */
  @Bean
  WebMvcConfigurer createWebMvcConfigurer() {
    return new WebMvcConfigurer() {
      @Override
      public void addResourceHandlers(ResourceHandlerRegistry registry) {
        registry.addResourceHandler("/static/**").addResourceLocations("/static/");
      }
    };
  }

  /* mvc_render */
  @Bean
  ViewResolver createViewResolver(@Autowired ServletContext servletContext) {
    PebbleEngine engine = new PebbleEngine.Builder().autoEscaping(true)
            // cache:
            .cacheActive(false)
            // loader:
            .loader(new ServletLoader(servletContext))
            // extension:
            .extension(new SpringExtension())
            // build:
            .build();
    PebbleViewResolver viewResolver = new PebbleViewResolver();
    viewResolver.setPrefix("/WEB-INF/templates/");
    viewResolver.setSuffix("");
    viewResolver.setPebbleEngine(engine);
    return viewResolver;
  }

  /* database */
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
