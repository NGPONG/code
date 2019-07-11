-- 创建数据库
create database Test1

--------------------------------------------------------------------------------------------

-- 删除数据库
drop database Test1

--------------------------------------------------------------------------------------------

-- 创建数据库和数据库的日志文件并更改它们的详细设置
create database Test2
on
(
	name='Test2',
	size=5MB,
	filegrowth=2MB,
	fileName='C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\DATA\Test2.mdf'
)
log on
(
	name='Test2_log',
	size=2MB,
	filegrowth=2MB,
	fileName='C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\DATA\Test2_log.ldf'
)

--------------------------------------------------------------------------------------------

-- 引用数据库
use Test1

--------------------------------------------------------------------------------------------

-- 立即执行以上语句
go

--------------------------------------------------------------------------------------------

-- 创建表
	--primary key		设置为主键
	--identity(n,m)		设置是否自动增长
	--null/not null		设置可空约束
	--default(n)			设置默认值约束
create table Employee
(
--	列名 类型 (一些约束) null/not null 
	EmpId int primary key identity(1,1) not null,
	EmpName nvarchar(32) null,
	EmpGender nchar(1) null,
	EmpAddress nvarchar(32) null,
	DelFlag smallint default(0) not null,
)

--------------------------------------------------------------------------------------------

-- 查询表中的内容
-- select 列名 from 表名 where 条件表达式
	--select	选择列，*号代表所有列
	--form		来自哪个表
	--where	条件表达式，查找符合条件的列所在的行，不加where则查找整个表的内容
select EmpId, EmpName, EmpGender, EmpAddress from dbo.Employee where EmpId>3

--------------------------------------------------------------------------------------------

-- 插入数据至某个表中
-- insert into  表名(列名1,列名2,列名3,....)  values(值1,值2,值3,....)：在指定表中增加新的一行数据
-- 当某个列的数据为自动增长或为默认值约束的时候，则不用写该列的列名和值
insert into dbo.Employee (EmpName,EmpAddress,EmpGender) values (N'刘德华',N'香港',N'男')

-------------------------------------------------------------------------------------------

-- 删除表中的数据
-- delete from 表名 where 条件表达式：删除该表中满足指定条件的那一行
-- 一定要加where
delete from dbo.EmployeeInfo where EmpID = 6

--------------------------------------------------------------------------------------------

-- 改变表中的数据
-- update 表名 set 列名1=更改的值,列名2=更改的值2 where 条件表达式
update dbo.Employee set EmpName = N'吴鹏' where EmpAge = 236

--------------------------------------------------------------------------------------------

