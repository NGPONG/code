package com.learnjava.entity;

public class User {
  private long Id;
  public long getId() {
    return Id;
  }
  public void setId(long id) {
    this.Id = id;
  }

  private String email;
  public String getEmail() {
    return email;
  }
  public void setEmail(String email) {
    this.email = email;
  }

  private String password;
  public String getPassword() { return password; }
  public void setPassword(String password) { this.password = password; }

  private String name;
  public String getName() {
    return name;
  }
  public void setName(String name) {
    this.name = name;
  }

  public User() {}
  public User(long id, String email, String password, String name) {
    this.Id = id;
    this.email = email;
    this.password = password;
    this.name = name;
  }

  @Override
  public String toString() {
    return String.format("User[id=%s, email=%s, name=%s, password=%s]", this.Id, this.email, this.name,
            this.password);
  }
}
