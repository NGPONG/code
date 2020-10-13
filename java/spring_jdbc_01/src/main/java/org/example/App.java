package org.example;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import org.example.services.*;

/**
 * Hello world!
 */
public class App {
  public static void main(String[] args) {
    ApplicationContext context = new AnnotationConfigApplicationContext(app_config.class);
    var usr_service = context.getBean(user_service.class);
    var lit = usr_service.get_user_info();
    for (user usr : lit) {
      System.out.println(usr.toString());
    }
  }
}
