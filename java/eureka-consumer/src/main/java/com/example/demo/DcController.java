package com.example.demo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@RestController
public class DcController {
  final Logger logger = LoggerFactory.getLogger(getClass());

  @Autowired
  LoadBalancerClient loadBalancerClient;
  @Autowired
  RestTemplate restTemplate;

  @GetMapping("/consumer")
  public String dc() {
    try {
      ServiceInstance serviceInstance = loadBalancerClient.choose("eureka-client");
      String url = "http://" + serviceInstance.getHost() + ":" + serviceInstance.getPort() + "/dc";
      logger.info(url);
      return restTemplate.getForObject(url, String.class);
    } catch(Exception e) {
      logger.error(e.getMessage());
      return e.getMessage();
    }
  }
}