package com.learnjava.web;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.learnjava.services.RedisService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RestController
@RequestMapping("/api/test")
public class TestController {
  @Autowired
  RedisService redis_servie;

  @GetMapping("/set_redis")
  public Map<String, Object> SetRedisKV() {
    redis_servie.set("NGPONG","REDIS: Hello,world!");
    return Map.of("msg", "SUCCESS");
  }

  @GetMapping("/get_redis/{key}")
  public Map<String, Object> GetRedisKV(@PathVariable("key") String _key) {
    return Map.of("value", redis_servie.get(_key));
  }
}
