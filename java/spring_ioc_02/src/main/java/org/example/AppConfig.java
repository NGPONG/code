package org.example;

import org.example.model.User;
import org.example.service.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import java.time.ZoneId;

@Configuration
@ComponentScan
public class AppConfig {
  public static void main(String[] args) {
    ApplicationContext context = new AnnotationConfigApplicationContext(AppConfig.class);
    UserService userService = context.getBean(UserService.class);
    User user = userService.login("bob@example.com", "password");
    System.out.println(user.getName());
  }

  /**
   *  Wired to org.example.service.MailService.zoneId.
   *  Function name is not requirement but return type is.
   */
  @Bean
  ZoneId wtf_test() {
    return ZoneId.of("Z");
  }
}
