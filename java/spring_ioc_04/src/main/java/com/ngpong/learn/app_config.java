package com.ngpong.learn;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan
public class app_config {
  public static void main(String[] args) {
    ApplicationContext ctx = new AnnotationConfigApplicationContext(app_config.class);
    var res_printer = ctx.getBean(app_serviece.class);
    res_printer.print_all();
  }
}
