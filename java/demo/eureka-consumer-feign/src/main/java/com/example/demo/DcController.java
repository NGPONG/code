package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DcController {
  @Autowired
  DcServices service;

  /* @breif 服务间调用 */
  @GetMapping("/consumer")
  public String consumer() {
    return service.consumer();
  }

  @GetMapping("/broken-test")
  public String broken_test() throws InterruptedException {
    return service.broken_test();
  }
}