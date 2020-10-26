package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.hystrix.dashboard.EnableHystrixDashboard;
/**
 * 默认的集群监控：通过URL http://turbine-hostname:port/turbine.stream开启，实现对默认集群的监控。
 * 指定的集群监控：通过URL http://turbine-hostname:port/turbine.stream?cluster=[clusterName]开启，实现对clusterName集群的监控。
 * 单体应用的监控：通过URL http://hystrix-app:port/hystrix.stream开启，实现对具体某个服务实例的监控。
 */
@SpringBootApplication
@EnableHystrixDashboard
public class hystrix_dashboard_application {
	public static void main(String[] args) {
		SpringApplication.run(hystrix_dashboard_application.class, args);
	}
}
