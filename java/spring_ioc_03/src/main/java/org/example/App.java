package org.example;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan
public class App 
{
    public static void main( String[] args ) throws Exception {
        ApplicationContext context = new AnnotationConfigApplicationContext(App.class);
        var cla_ent = context.getBean(StringFactaoryBean.class);
        System.out.println(cla_ent.getObject());
    }
}
