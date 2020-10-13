package com.itranswarp.learnjava.service;

import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;

import org.springframework.stereotype.Component;

@Component
public class MailService {

	ZoneId zoneId = ZoneId.systemDefault();

	public String getTime() {
		return ZonedDateTime.now(this.zoneId).format(DateTimeFormatter.ISO_ZONED_DATE_TIME);
	}

	public void sendLoginMail(User user) {
		System.err.println(String.format("Hi, %s! You are logged in at %s", user.getName(), getTime()));
	}

	public void sendRegistrationMail(User user) {
		System.err.println(String.format("Welcome, %s!", user.getName()));

	}
}
