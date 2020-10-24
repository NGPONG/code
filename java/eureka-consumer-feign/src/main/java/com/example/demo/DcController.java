package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DcController {
  @Autowired
  DcClient dc_client;

  @GetMapping("/consumer")
  public String dc() {
    try {
      return dc_client.consumer();
    } catch(Exception ex) {
      return ex.getMessage();
    }
  }
}