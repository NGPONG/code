--select * from dbo.UserInfo


---- 判断一张表中，某一列数据所代表的含义
---- 两种用法
---- 用法一：类似于c#中的 switch case
---- select  case  列名  when  该列所对应的值  then  定义的含义  else  定义的含义  end  from  表名
--select *,case DelFlag when 0 then N'未删除' when 1 then N'删除' else N'未知' end as N'删除状态' from dbo.UserInfo




---- 判断一张表中，某一列数据所代表的含义
---- 两种用法
---- 用法二：类似于c#中的 if - else if - else
---- select  case  when  该列所对应的值的表达式  then  定义的含义  else  定义的含义  end  from  表名
--select *,case when DelFlag < 1 then N'未删除' when DelFlag=1 then N'删除' else N'真的删除' end as N'删除状态' from dbo.UserInfo





---- 声明一个变量，并且给变量赋值，最后打印变量

---- 声明变量 : declare  @变量名  类型
--declare @variable int

---- 两种方式给变量赋值 : 
---- 1. set  @变量名  =  值
--set @variable = (select count(1) from dbo.UserInfo where DelFlag <1)
---- 2. select  @变量名  =  值
--select @variable = 10

---- 打印 : print  变量
--print @variable





---- if  else if  else / if else  条件判断的使用
---- if( 表达式 )
----		begin  
----			SQL语句  
----		end
---- else if( 表达式 )
----		begin  
----			SQL语句  
----		end
---- else
----		begin 
----			SQL语句  
----		end

--declare @n int -- 声明变量
--set @n = 10 -- 给变量赋值
--if(@n = 10)
--	begin
--		select * from dbo.UserInfo
--	end
--else if(@n <10)
--	begin
--		select UserName from dbo.UserInfo
--	end
--else
--	begin
--		select ID from dbo.UserInfo
--	end

	 



---- while循环的使用
---- while( 表达式 )
----		begin
----			SQL语句
----		end
--declare @i int
--select @i = 0
--while(@i<100)
--	begin
--		print @i
--		select @i=@i+1
--	end






--use [AdventureWorksLT2008]
---- 子查询
---- 1. 把一个查询的结果所返回的表，当作二次查询所需的表来使用
---- 注意：当把子查询当作表来使用的时候，必须用 as 来为查询所返回的表定义一个别名
--select * from (select CustomerID from SalesLT.Customer where Title = 'Mr.' ) as T where T.CustomerID < 50

---- 2. 把一个查询的结果当作是一个表达式来使用
---- 注意：子查询所返回的列，必须与二次查询中的 where/haveing… 后面所判断的列相对应

---- 二次查询判断二次查询的表中所有CustomerID大于子查询所返回的平均数的数据
--select * from SalesLT.Customer where CustomerID > (select avg(CustomerID) from SalesLT.Customer )

---- 二次查询通过 in 来判断二次查询的表中的CompanyName的列，符合子查询所返回的CompanyName列的数据
--select * from SalesLT.Customer where CompanyName in
--(
-- select CompanyName from SalesLT.Customer group by CompanyName having count(1) >=2
-- )


---- 查询顾客表中属于同一家公司超过两个顾客的公司名称
--select * from SalesLT.Customer where CompanyName in( select CompanyName from SalesLT.Customer group by CompanyName having count(1) >=2)

---- 查询顾客表中  相同公司人数最多的 顾客信息
--select * from SalesLT.Customer where CompanyName =( select top 1 CompanyName from SalesLT.Customer group by CompanyName order by count(1) desc )

---- 查询 相同公司人数最多的顾客的订单信息
--select * from SalesLT.SalesOrderHeader where CustomerID in
--(
--select CustomerID from SalesLT.Customer where CompanyName in ( select top 1 CompanyName from SalesLT.Customer group by CompanyName order by Count(1) desc)
--)

--use damon
---- 查询山东省的所有城市的信息
--select * from dbo.AreaFull where AreaPid in ( select AreaId from dbo.AreaFull where AreaName = N'山东省')

---- --查询山东省中所有县级市的
--select * from dbo.AreaFull where AreaPid in
--(
--select AreaId from dbo.AreaFull where AreaPid in ( select AreaId from dbo.AreaFull where AreaName = N'山东省')
--)
--and AreaName like '%县'







---- 双order by排序分页法 : 越过多少条，取多少条

---- 取第 m 页的数据，每页有 n 条数据
---- select  top  n  *  from  表名  where  列名ID  not  in
---- (
---- select  top  ( ( m - 1 ) * n )  列名ID  from  表名  order  by  列名ID
---- )
---- order  by  列名ID
---- n = 每页有几条数据     m = 取第几页的数据

---- 以下代码的要求为：取第4页的数据，每页数据有3条
--select top 3 * from dbo.UserInfo where ID not in --二次查询负责取多少条
--(
--select top ((4-1)*3) ID from dbo.UserInfo order by ID --子查询的结果表示需要越过多少条
--)
--order by ID

---- row_number() over() 函数的分页方法

---- 取第 m 页的数据，每页有 n 条数据
---- select  列名  from
---- ( select  列名 , row_number()  over( order by 列名 )  as  自定义列名R  from  表名 )  as  自定义表名T
---- where  自定义列名R  between  ( ( m - 1 ) * n + 1 )  and  ( n*m )
---- n = 每页有几条数据     m = 取第几页的数据

---- 以下代码的要求为：取第5页的数据，每页数据有3条
--select * from
--(select *,row_number() over(order by ID) as num from dbo.UserInfo) as T
--where T.num between ((5-1)*3+1) and (5*3)









---- row_number()的使用必须配合开窗函数，且开窗函数括号里必须写一个order by
---- select  row_number()  over( order  by  列名 )
--select row_number() over( order by ID ) from dbo.UserInfo

---- 开窗函数 over()
---- select  函数名 , over( 选项 )  from  表名
--select count(1) over(),* from dbo.UserInfo




-- inner join : 内连接
-- 通过一个 on 的条件判断连接两个表中的数据
-- 但，只有符合on条件的数据才会连接至表中
select * from dbo.Product as P inner join dbo.Category as C on P.CategoryID = C.CatId

-- right join : 右连接
-- 通过一个 on 的条件判断连接两个表中的数据
-- 但，要是存在不匹配 on的条件 也会返回数据，并且只会返回右表的数据，左表的数据为null
select * from dbo.Product as P right join dbo.Category as C on P.CategoryID = C.CatId

-- left join : 左连接
-- 通过一个 on 的条件判断连接两个表中的数据
-- 但，要是存在不匹配 on的条件 也会返回数据，并且只会返回左表的数据，右表的数据为null
select * from dbo.Product as P left join dbo.Category as C on P.CategoryID = C.CatId

-- full join : 全连接
-- 通过一个 on 的条件判断连接两个表中的数据
-- 但，要是存在不匹配 on的条件 也会返回数据，并且左右表的数据都返回，并且都存在null值
-- full join全连接可以看成是 left join 和 right join 的合并使用
select * from dbo.Product as P full join dbo.Category as C on P.CategoryID = C.CatId


-- cross join : 笛卡儿积连接
-- 连接两个表的数据，通过笛卡儿积来计算出所有可以匹配的内容
select * from dbo.Product as P
cross join dbo.Category as C