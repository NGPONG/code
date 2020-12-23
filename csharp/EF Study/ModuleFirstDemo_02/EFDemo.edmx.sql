
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 10/07/2019 20:57:34
-- Generated from EDMX file: C:\Users\NGPONG\Desktop\code\C#和HTML\EF Study\ModuleFirstDemo_02\EFDemo.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [EFDemo1];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------


-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------


-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'ClassInfo'
CREATE TABLE [dbo].[ClassInfo] (
    [ClassInfoId] int IDENTITY(1,1) NOT NULL,
    [ClassName] nvarchar(64)  NULL
);
GO

-- Creating table 'Student'
CREATE TABLE [dbo].[Student] (
    [StudentId] int IDENTITY(1,1) NOT NULL,
    [StudentName] nvarchar(64)  NULL,
    [StudentAge] int  NULL,
    [ClassInfoId] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [ClassInfoId] in table 'ClassInfo'
ALTER TABLE [dbo].[ClassInfo]
ADD CONSTRAINT [PK_ClassInfo]
    PRIMARY KEY CLUSTERED ([ClassInfoId] ASC);
GO

-- Creating primary key on [StudentId] in table 'Student'
ALTER TABLE [dbo].[Student]
ADD CONSTRAINT [PK_Student]
    PRIMARY KEY CLUSTERED ([StudentId] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [ClassInfoId] in table 'Student'
ALTER TABLE [dbo].[Student]
ADD CONSTRAINT [FK_ClassInfo_Student]
    FOREIGN KEY ([ClassInfoId])
    REFERENCES [dbo].[ClassInfo]
        ([ClassInfoId])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_ClassInfo_Student'
CREATE INDEX [IX_FK_ClassInfo_Student]
ON [dbo].[Student]
    ([ClassInfoId]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------