package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.zuul.EnableZuulProxy;
import org.springframework.context.annotation.Bean;

/**
 * Default route:
 * 	- /[server_name]/**
 */

@EnableZuulProxy
@SpringBootApplication
public class api_gateway_application {
	@Bean
 	public global_access_filter accessFilter() {
 		return new global_access_filter();
	}

	public static void main(String[] args) {
		SpringApplication.run(api_gateway_application.class, args);
	}
}
