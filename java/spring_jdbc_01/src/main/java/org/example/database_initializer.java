package org.example;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;

@Component
public class database_initializer {
  @Autowired
  JdbcTemplate jdbc_template;

  @PostConstruct
  public void init() {
    /*
    jdbc_template.update("IF EXISTS(SELECT * FROM sysobjects WHERE name='users')"
            + "DROP TABLE [users]"

            + "CREATE TABLE [dbo].[users]( "
            + "[Id] [int] IDENTITY(1,1) NOT NULL, "
            + "[email] [varchar](128) NOT NULL, "
            + "[password] [varchar](128) NOT NULL, "
            + "[name] [varchar](128) NOT NULL, "
            + "CONSTRAINT [PK_users] PRIMARY KEY CLUSTERED ( [Id] ASC ) "
            + "WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]"
            + ") ON [PRIMARY]");
     */

    System.out.println("init ok");
  }
}
