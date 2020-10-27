package com.example.demo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DcController {
  final Logger logger = LoggerFactory.getLogger(getClass());

  @Autowired
  DiscoveryClient discoveryClient;

  @Value("${server.port}")
  private String port;

  @GetMapping("/dc")
  public String dc() {
    String services = "find services: " + discoveryClient.getServices();
    logger.info(services);
    return "[" + port + "]: " + services;
  }
}
