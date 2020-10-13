package com.learnjava.web;

import com.learnjava.entity.User;
import com.learnjava.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api")
public class UserController {
  @Autowired
  UserService user_service;

  @GetMapping("/users/{name}")
  public User user(@PathVariable("name") String name) {
    return user_service.GetUserByName(name);
  }
}
