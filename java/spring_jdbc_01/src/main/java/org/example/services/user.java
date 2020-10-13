package org.example.services;

public class user {

  private long Id;
  private String email;
  private String password;
  private String name;

  public user() {
  }

  public user(long id, String email, String password, String name) {
    this.Id = id;
    this.email = email;
    this.password = password;
    this.name = name;
  }

  public long getId() {
    return Id;
  }

  public void setId(long id) {
    this.Id = id;
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  @Override
  public String toString() {
    return String.format("User[id=%s, email=%s, name=%s, password=%s]", this.Id, this.email, this.name,
            this.password);
  }
}
