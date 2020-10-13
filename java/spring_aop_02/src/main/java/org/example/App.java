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
  public static void main(String[] args) throws InterruptedException {
    ApplicationContext ctx = new AnnotationConfigApplicationContext(App.class);
    var user_services = ctx.getBean(UserServices.class);
    user_services.start();
  }
}
