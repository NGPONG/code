package org.example;

import org.springframework.beans.factory.FactoryBean;
import org.springframework.stereotype.Component;

@Component
public class StringFactaoryBean implements FactoryBean<String> {

  @Override
  public String getObject() throws Exception {
    return "Hello,world";
  }

  @Override
  public Class<?> getObjectType() {
    return String.class;
  }
}
