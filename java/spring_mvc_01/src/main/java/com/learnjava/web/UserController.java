package com.learnjava.web;

import com.learnjava.entity.User;
import com.learnjava.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.Map;

@RestController
@RequestMapping("/api/users")
public class UserController {
  @Autowired
  UserService user_service;

  @GetMapping("/{name}")
  public User GetUserByName(@PathVariable("name") String name) {
    return user_service.GetUserByName(name);
  }

  @GetMapping("/input/{msg}")
  public Map<String, Object> GetMsg(@PathVariable("msg") String msg) {
    return Map.of("msg", msg);
  }
}
