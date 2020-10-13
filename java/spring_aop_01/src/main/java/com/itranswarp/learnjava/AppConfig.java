package com.itranswarp.learnjava;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

import com.itranswarp.learnjava.service.UserService;

@Configuration
@ComponentScan
@EnableAspectJAutoProxy
public class AppConfig {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		ApplicationContext context = new AnnotationConfigApplicationContext(AppConfig.class);
		UserService userService = context.getBean(UserService.class);
		userService.register("test@example.com", "password", "test");
		userService.login("bob@example.com", "password");
		System.out.println(userService.getClass().getName());
	}
}
