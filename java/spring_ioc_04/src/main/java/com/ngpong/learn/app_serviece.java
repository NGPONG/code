package com.ngpong.learn;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.Resource;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Component
public class app_serviece {
  @Value("classpath:/logo.txt")
  public Resource res_logo;

  @Value("classpath:/app.properties")
  public Resource res_property;

  private String _logo;
  private List<String> _propertys;

  @PostConstruct
  private void init() throws IOException {
    /* logo */
    try(var reader = new BufferedReader(new InputStreamReader(res_logo.getInputStream(), StandardCharsets.UTF_8))) {
      _logo = reader.lines().collect(Collectors.joining("\n"));
    }

    /* property */
    try(var reader = new BufferedReader(new InputStreamReader(res_property.getInputStream(),StandardCharsets.UTF_8))) {
      var tmp = reader.lines().collect(Collectors.filtering(s -> {
        return s != null && !s.isBlank() && s.charAt(0) != '#';
      }, Collectors.toList()));

      _propertys = new ArrayList<>();
      tmp.forEach((String s) -> {
        _propertys.add(s.split("=")[1]);
      });
    }
  }

  public void print_all() {
    System.out.println(this._logo + "\n");

    for (String property : _propertys) {
      System.out.println(property);
    }
  }
}
