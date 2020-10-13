package org.example;

import org.springframework.stereotype.Component;

@Component
public class UserServices {
  @MetricTime("NGPONG")
  public void start() throws InterruptedException {
    Thread.sleep(2000);

    System.out.println("hello,world!");
  }
}
