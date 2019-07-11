
-- 创建全局临时表
-- 方法和创建普通的表相同，只是要在创建的表明前面+两个#

-- 方式一：
create table ##TemporaryTable
(
	TemporaryID int not null,
	TemporaryName nvarchar(32) not null
)
-- 方式二：
select * into ##TemporaryTable from dbo.UserInfo

-- 只有当所有用户都断开了对全局临时表的连接和会话的操作后，临时表才会自动释放掉
-- 我们也可以手动的释放掉全局临时表
drop table ##TemporaryTable










-- SQL中捕获异常的方法，与c#语法类似
-- begin try
-- SQL语句
-- end try
-- begin catch
-- SQL语句
-- end catch
begin try
	update dbo.UserInfo set ErrorTime=N'哈哈' where ID=2
end try
begin catch
	print N'失败了'
end catch












begin try
	begin transaction -- 开启事务
		update dbo.UserInfo set UserName=N'asqw' where ID=2;
		update dbo.UserInfo set ErrorTime=N'哈哈' where ID=3
	commit transaction -- 提交事务
end try
begin catch
	rollback transaction -- 回滚事务
end catch
go














-- 判断系统的所有对象中，是否已存在需要创建的存储过程的名字，如果存在，则删除再创建一个新的
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' 存储过程的名字 ' ) )   drop  procedure  存储过程的名字
-- exists()：判断的时候必须使用这个函数
-- sys.all_objects：代表系统中的所有对象
if(exists(select * from sys.all_objects where name='Pro_UserInfo_GetUserInfo'))
	drop procedure Pro_UserInfo_GetUserInfo
go
-- 创建存储过程
-- create  procedure  存储过程名字
-- 输入参数名  输入参数类型
-- 输出参数名  输出参数类型：当存储过程中存在输出参数，那么在存储过程执行的SQL脚本（as -> go）结束前，必须为其赋值！
-- as
-- 自己定义的一坨SQL脚本
-- go
create procedure Pro_UserInfo_GetUserInfo
@Num int,
@test int output
as
select * from dbo.UserInfo where ID < @Num
set @test=(select count(1) from dbo.UserInfo where ID < @Num)
go
-- 调用存储过程
-- exec  存储过程名  输出参数 , 输入参数名 out
-- 当我们在存储过程中写了输出参数、输入参数，那么在调用的时候也需要在后面传参
-- 当我们在一个存储过程中定义了一个输出参数，那么在调用存储过程前，我们需要自己定义一个参数
-- 然后在执行存储过程的后面写：输出参数名 out
-- 当存储过程执行完成后，我们就可以获取到该存储过程所返回的参数的值
declare @test int
exec Pro_UserInfo_GetUserInfo 10,@test out
print @test


-- 创建分页存储过程
if(exists(select * from sys.all_objects where name='Pro_UserInfo_GetPages'))
	drop procedure Pro_UserInfo_GetUserInfo
go
create procedure Pro_UserInfo_GetPages
@pageIndex int,
@pageSize int,
@count int output
as 
	select * from
	(select *,row_number() over(order by ID) as rowNumber from dbo.UserInfo) as T
	where T.rowNumber between ( ( @pageIndex - 1 )*@pageSize + 1 ) and ( @pageIndex * @pageSize )
	--输出参数赋值
	set @count=(select count(1) from dbo.UserInfo)
go

--调用分页存储过程
declare @count int
exec Pro_UserInfo_GetPages 7,3,@count out
print @count


-- 调用系统的存储过程
exec sp_databases														-- 查看所有的数据库

exec sp_tables																-- 查看指定数据库中的所有的表

exec sp_columns UserInfo,dbo,damon,UserName		-- 查看列

exec sp_helpindex 'UserInfo'										-- 查看索引

exec sp_helpconstraint 'UserInfo'								-- 查看约束

exec sp_stored_procedures											-- 查看存储过程

exec sp_helptext 'Pro_UserInfo_GetPages'					-- 查看存储过程的详细定义

exec sp_rename 'ProductUpdate','Product'				-- 更改 表、索引、列、触发器等的名字

exec sp_renamedb 'damon','demo'							-- 更改数据库的名称

exec sp_defaultdb 'master','myDataBase'					-- 更改登录名默认数据库的名称

exec sp_helpdb 'damon'												-- 查看数据库帮助、具体信息


-- 存储过程动态的执行SQL脚本

-- 方式一：通过变量来执行
-- 注意：是用括号
declare @SqlsScript nvarchar(max) -- 定义变量
select @SqlSscript = 'select * from dbo.UserInfo' -- 变量赋值
exec (@SqlSscript) -- 动态执行SQL脚本

-- 方式二：直接书写字符串
-- 注意：使用括号
exec ('select * from dbo.UserInfo') -- 动态执行SQL脚本

-- 方式三：通过系统存储过程来调用 (兼容性更强)
declare @SqlScript nvarchar(max) -- 定义变量
select @SqlScript = 'select * from dbo.UserInfo' -- 变量赋值
exec sp_executesql @SqlScript -- 动态执行SQL脚本
go












-- 标量值函数
-- 判断系统的所有对象中，是否已存在需要创建的函数的名字，如果存在，则删除再创建一个新的
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' 函数的名字 ' ) )   drop  function  函数的名字
-- exists()：判断的时候必须使用这个函数
-- sys.all_objects：代表系统中的所有对象
if(exists(select * from sys.all_objects where name='Fun_GetUserInfoCount'))
drop function Fun_GetUserInfoCount
go
-- 创建标量值函数
-- create  function  函数名  (参数名  参数类型)
-- returns  返回值类型
-- as
-- begin
--	自己定义的一坨SQL脚本
-- return  参数
-- end
create function Fun_GetUserInfoCount(@Number int)
returns int
as
begin
	declare @result int
	select @result = (select count(1) from dbo.UserInfo where DelFlag = @Number )
	return @result
end
go
-- 调用标量值函数
-- select  函数名 ( 参数 )
select dbo.Fun_GetUserInfoCount(1)


-- 表值函数
-- 判断系统的所有对象中，是否已存在需要创建的函数的名字，如果存在，则删除再创建一个新的
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' 函数的名字 ' ) )   drop  function  函数的名字
-- exists()：判断的时候必须使用这个函数
-- sys.all_objects：代表系统中的所有对象
if(exists(select * from sys.all_objects where name = 'Fun_UserInfo'))
-- 删除函数
-- drop  function  函数名
drop function Fun_UserInfo
go
-- 创建表值函数
-- create  function  函数名  (参数名  参数类型)
-- returns  table
-- as
-- return  查询结果返回表的SQL脚本
create function Fun_UserInfo(@Num int)
returns table
as
	return select * from dbo.UserInfo where DelFlag = @Num
go

-- 调用表值函数
-- select  列名  from  表值函数 ( 参数 )
select * from Fun_UserInfo(0)











-- 插入语句也能够返回条数据
-- 使用inserted表，来获取当前插入语句至表中所对应行的ID
-- 只能insert使用！！
insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) output inserted.ID values ('qwesaf','qwreqr14',0,'2018-03-16 19:34:26.000',1)

-- 触发器
-- 判断系统的所有对象中，是否已存在需要创建的触发器的名字，如果存在，则删除再创建一个新的
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' 函数的名字 ' ) )   drop  function  函数的名字
-- exists()：判断的时候必须使用这个函数
-- sys.all_objects：代表系统中的所有对象
if(exists(select *  from sys.all_objects where name='Tr_UserInfo_Insert'))
-- 删除触发器
-- drop  trigger  触发器名
drop trigger Tr_UserInfo_Insert
go
-- 创建 for 触发器
-- create  trigger  触发器名  on  表名
-- for  delete、update、insert操作
-- as
-- begin
--	自己定义的当成功触发触发器后所执行的SQL脚本
-- end
create trigger Tr_UserInfo_Insert on dbo.UserInfo
for insert
as
begin
	declare @ID int
	select @ID = (select ID from inserted)

	update dbo.UserInfo set UserName = UserName + cast(getdate() as nvarchar(max)) where ID = @ID		
end
-- 触发触发器的事件
-- 因为我们定义的触发器是insert的，所以当我们执行insert语句的时候，就会自动触发触发器
insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) values('qweqsdd','12sd',0,getdate(),0)
go



create trigger Tr_UserInfo_Update on dbo.UserInfo
for Update
as
begin
	declare @DUserName nvarchar(32)
	declare @DUserPassWord nvarchar(32)

	select @DUserName = (select UserName from deleted)
	select @DUserPassWord = (select UserPassWord from deleted)

	declare @IUserName nvarchar(32)
	declare @IUserPaswWord nvarchar(32)

	select @IUserName = (select UserName from inserted)
	select @IUserPaswWord = (select UserPassWord from inserted)

	declare @ID int
	select @ID = (select ID from inserted)

	update dbo.UserInfo set UserName = @DUserName+@IUserName,UserPassWord = @DUserPassWord + @IUserPaswWord from dbo.UserInfo where ID = @ID
end

update dbo.UserInfo set UserName = N'修改了！',UserPassWord = N'我也被修改了！' from dbo.UserInfo where ID = 3
go



-- 触发器
-- 判断系统的所有对象中，是否已存在需要创建的触发器的名字，如果存在，则删除再创建一个新的
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' 函数的名字 ' ) )   drop  function  函数的名字
-- exists()：判断的时候必须使用这个函数
-- sys.all_objects：代表系统中的所有对象
if(exists(select * from sys.all_objects where name = 'Tr_UserInfo_UpdateReplaceSelect'))
-- 删除触发器
-- drop  trigger  触发器名
drop trigger Tr_UserInfo_UpdateReplaceSelect
go
-- 创建 instead of 触发器
-- create  trigger  触发器名  on  表名
-- instead  of  update、delete、insert操作
-- as
-- begin
-- 自己定义SQL脚本，当触发触发器后，替换原有的触发触发器的SQL脚本
-- end
create trigger Tr_UserInfo_UpdateReplaceSelect on dbo.UserInfo
instead of insert
as
begin
	declare @UserName nvarchar(32)
	select @UserName = (select UserName from inserted)
	declare @ID int
	select @ID = (select ID from inserted)
	
	select * from dbo.UserInfo where UserName = @UserName --替换原有的SQL脚本

	print @UserName
	print @ID
end
-- 触发触发器的事件
-- 因为我们定义的触发器是insert的，所以当我们执行insert语句的时候，就会自动触发触发器
insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) values('pengqi123','1234qsd',0,getdate(),0)









