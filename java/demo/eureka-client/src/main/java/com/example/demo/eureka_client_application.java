package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.eureka.EnableEurekaClient;

@SpringBootApplication
@EnableEurekaClient
public class eureka_client_application {

	public static void main(String[] args) {
		SpringApplication.run(eureka_client_application.class, args);
	}

}
