package com.example.demo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@RestController
public class ConsumerController {
  final Logger logger = LoggerFactory.getLogger(getClass());

  @Autowired
  EchoService echo_service;

  @Autowired
  RestTemplate rest_template;

  @GetMapping("/echo-service/{str}")
  public String feign(@PathVariable String str) {
    logger.info("nacos-consumer-feigon hit request");

    return echo_service.echo(str);
  }

  @GetMapping("/echo-temp/{str}")
  public String temp(@PathVariable String str) {
    logger.info("nacos-consumer-template hit request");

    return rest_template.getForObject("http://nacos-provider/echo/" + str, String.class);
  }
}