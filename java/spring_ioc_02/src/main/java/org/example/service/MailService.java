package org.example.service;

import org.example.model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;

@Component
public class MailService {
  @Autowired
  private ZoneId zoneId;

  private String getTime() {
    return ZonedDateTime.now(this.zoneId).format(DateTimeFormatter.ISO_ZONED_DATE_TIME);
  }

  public void sendLoginMail(User user) {
    System.err.println(String.format("Hi, %s! You are logged in at %s", user.getName(), getTime()));
  }

  public void sendRegistrationMail(User user) {
    System.err.println(String.format("Welcome, %s!", user.getName()));
  }
}
