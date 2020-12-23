
-- 定义一个游标，让游标指向一个查询SQL的结果集
-- declare  游标名  cursor  for  查询SQL语句
declare demoCursor cursor for (select ID,UserName,UserPassWord from dbo.UserInfo)

-- 打开游标，只有我们打开了游标才能够使用
-- open  游标名
open demoCursor

-- 把游标的数据取出来，并把数据放到自己定义的变量中去
-- 注意：当我们定义好了一个游标，并且打开了它，游标就会指向查询结果集的第0行数据，每执行一次这条语句则往下一行数据中走
-- fetch  next  from  游标名  into  变量名

-- 定义三个变量
declare @UserName nvarchar(32)
declare @ID int
declare @UserPassWord nvarchar(32)
-- 执行游标的数据取出语句
-- 注意：变量名的书写顺序必须跟定义游标时，所指向的查询SQL脚本结果集语句的书写顺序相同
while(@@FETCH_STATUS = 0)
	begin
		fetch next from demoCursor into @ID,@UserName,@UserPassWord
		-- 打印变量
		print @ID
		print @UserName
		print @UserPassWord
	end

--每当我们使用完成后必须要关闭游标
close demoCursor
deallocate demoCursor

