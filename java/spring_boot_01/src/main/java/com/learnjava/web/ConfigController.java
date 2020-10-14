package com.learnjava.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/api/config")
public class ConfigController {
  @Autowired
  StorageConfiguration storage_config;

  @GetMapping("/storage/")
  public Map<String,StorageConfiguration> GetStorageConfig() {
    return Map.of("data", storage_config);
  }

  @Configuration
  @ConfigurationProperties("storage.local")
  public class StorageConfiguration {
    private String rootDir;
    private int maxSize;
    private boolean allowEmpty;
    private List<String> allowTypes;

    public String getrootDir() {
      return this.rootDir;
    }
    public int getmaxSize() {
      return this.maxSize;
    }
    public boolean getallowEmpty() {
      return this.allowEmpty;
    }
    public List<String> getallowTypes() {
      return this.allowTypes;
    }

    public void setrootDir(String _rootDir) {
      this.rootDir = _rootDir;
    }
    public void setmaxSize(int _maxSize) {
      this.maxSize = _maxSize;
    }
    public void setallowEmpty(boolean _allowEmpty) {
      this.allowEmpty = _allowEmpty;
    }
    public void setallowTypes(List<String> _allowTypes) {
      this.allowTypes = _allowTypes;
    }
  }
}
