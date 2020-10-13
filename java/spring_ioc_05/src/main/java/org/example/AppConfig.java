package org.example;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.*;

@Configuration
@ComponentScan
@PropertySource("app.properties") /* PATH: resources/app.properties */
public class AppConfig {
  public void init() {
    ApplicationContext ctx = new AnnotationConfigApplicationContext(AppConfig.class);
    var smtp_config = ctx.getBean(org.example.smtp_config.class);
    System.out.println("smtp_config: " + smtp_config.smtp_port);

    var mail_service = ctx.getBean(MailServices.class);
    System.out.println("mail_service: " + mail_service.mail_services_port);
  }

  @Bean
  @Qualifier("smtp_port")
  String GetSmtpPortNumber(@Value("${smtp.port:6666}") String _port) {
    return _port;
  }
}
