package org.example;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class MailServices {
  @Value("#{smtp_config.smtp_port}")
  String mail_services_port;
}
