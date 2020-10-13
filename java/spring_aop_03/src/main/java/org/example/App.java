package org.example;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

@Configuration
@ComponentScan
@EnableAspectJAutoProxy
public class App {
  public static void main(String[] args) {
      ApplicationContext context = new AnnotationConfigApplicationContext(App.class);
      var usr = context.getBean(UserServices.class);

      System.out.println(usr.get_name());

      usr.Say();
  }
}
