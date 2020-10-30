package com.example.demo;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

@FeignClient(name = "nacos-provider")
public interface EchoService {
  @GetMapping("/echo/{msg}")
  public String echo(@PathVariable String msg);
}
