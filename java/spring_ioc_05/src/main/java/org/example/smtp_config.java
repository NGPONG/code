package org.example;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
public class smtp_config {
  @Autowired
  @Qualifier("smtp_port")
  public String smtp_port;
}
