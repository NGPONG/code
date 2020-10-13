package org.example;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class LoggingAspect {
  @Before("execution(public * org..*.UserServices.*(..))")
  public void doAccessCheck() {
    System.err.println("[Before] do access check...");
  }
}
