package com.example.demo;

import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class DcServices {
  @Autowired
  DcClient client;

  @HystrixCommand(fallbackMethod = "fallback")
  public String consumer() {


    return client.dc();
  }

  @HystrixCommand(fallbackMethod = "fallback")
  public String broken_test() throws InterruptedException {
    Thread.sleep(1000);
    return "hello,world!";
  }

  public String fallback() {
    return "REQUEST BROKEN";
  }
}
