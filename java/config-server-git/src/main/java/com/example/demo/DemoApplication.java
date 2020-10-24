package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.config.server.EnableConfigServer;

/**
 * URL:
 * - /{application}-{profile}.yml
 * - /{application}/{profile}[/{label}]
 * - /{label}/{application}-{profile}.yml
 * - /{application}-{profile}.properties
 * - /{label}/{application}-{profile}.properties
 */

@EnableConfigServer
@SpringBootApplication
public class DemoApplication {
	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}
}
