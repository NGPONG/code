package org.example.service;

import org.example.model.User;

import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;

public class MailService {
  private ZoneId zoneId = ZoneId.systemDefault();

  public void setZoneId(ZoneId zoneId) {
    this.zoneId = zoneId;
  }

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
