package org.example;

import org.springframework.stereotype.Component;

@Component
public class UserServices {
  public String user_name = "NGPONG";

  public void Say() {
    System.out.println("hello,world");
  }

  public String get_name() {
    return this.user_name;
  }
}
