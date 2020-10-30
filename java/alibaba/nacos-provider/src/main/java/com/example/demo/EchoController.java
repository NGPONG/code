package com.example.demo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class EchoController {
  final Logger logger = LoggerFactory.getLogger(getClass());

  @Value("${server.port}")
  private String port;

  @GetMapping("/echo/{msg}")
  public String echo(@PathVariable String msg) {
    logger.info("nacos-provider hit request");

    return "127.0.0.1:" + port + "[" + msg + "]\n";
  }
}