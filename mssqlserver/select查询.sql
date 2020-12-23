-------------------------------------------------------------------------------------------------------

-- 给指定列/表达式/表取别名
-- 列名/表达式/表  as  别名
select ProName as 姓名 from dbo.Product
select 5*5 as 数字
select 表名.ProName,表名.* from dbo.Product as 表名

-- 给某个表中加入一个常数列，行数对应表中的行数
-- select  常数  from  表名
-- 注意：并没有真正的给表中的内容添加一个常数列的数据，只是添加进去，然后查询出结果而已
select 'qweqwe',* from dbo.Product

-- 查询常量/系统函数/表达式的值/表中列名所对应的值
-- select  常量/系统函数/表达式/列名/……
select 'sadasd' --常量
select getdate() --系统函数
select 1+3 --表达式
select ProName from dbo.Product --列名

-------------------------------------------------------------------------------------------------------

-- 聚合函数

-- 取表中的行数
-- select  count(常量值/*)  from  表名
-- count(*) : 找表中最短的列进行行数的统计
-- count(常量值) : 对常数列进行统计，等同于 -> select '常量' from 表名
select count(1) as 行数 from dbo.Product

-- 取表中指定列数据的平均值
-- select  avg(列名1),avg(列名2)  from  表名
select avg(ProductID) as 平均值1,avg(ListPrice) as 平均值2 from SalesLT.Product

-- 去表中数据的总和
-- select  sum(列名1),sum(列名2)  from  表名
select sum(ProductID) as 总和1,sum(ListPrice) as 总和2 from SalesLT.Product

-- 取表中数据的最大值/最小值
-- select  max/min(列名1),max/min(列名2)  from  表名
select max(ProductID) as 最大值,min(ListPrice) as 最小值 from SalesLT.Product

-------------------------------------------------------------------------------------------------------

-- 截取最上面n行的数据
-- select  top  n  列名/*  from  表名 
select top 2 * from SalesLT.Product

-- 指定列升序 asc/降序排序 desc
-- select  列名  from  表名  order by  列名  asc/desc
select * from SalesLT.Product order by StandardCost
-- 当指定多行列的时候注意：
-- 我们所指定的多行列会合并成一个排序的标准
-- select  列名1,列名2  from  表名  order by  列名1 asc/desc,列名2 asc/desc
select StandardCost,ProductID from SalesLT.Product order by StandardCost asc,ProductID desc

-- top和order by的配合使用
select top 3 * from SalesLT.Product order by ProductID asc

-------------------------------------------------------------------------------------------------------

-- 去掉指定列中重复的数据
-- select  distinct  列名  from  表名 
select distinct Color from SalesLT.Product
-- 当指定多行列的时候注意
-- select  distinct  列名1,列名2  from  表名
-- 会把两个列当作一个去重复的标准，然后去侦察每一行中与该标准重复的行
select distinct Color,Name from SalesLT.Product

-------------------------------------------------------------------------------------------------------

-- 条件过滤查询 where

-- 多条件过滤： and并且 or或者 not取非（优先级：not > and >or）
-- select  *  from  表名  where  表达式
select * from SalesLT.Customer where CustomerID>10 and CustomerID <20 or LastName != 'Gee'
select * from SalesLT.Customer where not(CustomerID > 20)
-- 区间查询：between and和in
-- select  列名  from  表名  where  列名  between  区间  and  区间
select * from SalesLT.Customer where CustomerID between 10 and 20

-- 模糊查询
-- 针对字符串查询的通配符：
-- 1. 0个或多个字符：%    2. 只有1个字符：_     3. 区间：[]
-- 特殊字符转义：'' = '  和  [ [ ] = [ 
-- select  列名  from  表名  where  列名  like  表达式(类似正则表达式)
select * from SalesLT.Customer where FirstName like '%th%'
select * from SalesLT.Customer where FirstName like '_rash%'
select * from SalesLT.Customer where CompanyName like '%[0-9]%'
select * from SalesLT.Customer where CompanyName like '%[[]%' 

-- 查询数据是否为null/not null
-- select  列名  from  表名  where  列名  is  null/not null
select * from SalesLT.Customer where MiddleName is not null

-------------------------------------------------------------------------------------------------------

-- 表中列信息的分组
-- select  分组的列/聚合函数  from  表名  group by  分组的列
-- 注意：1. 注意SQL语句的执行顺序
--           2. select后面必须写 我们所分组的列名：group by 的列名
select Title,count(1),sum(CustomerID) from SalesLT.Customer group by Title  having count(1) >5

-- 分组过滤条件
-- select  分组的列/聚合函数  from  表名   group by  分组的列  having  聚合函数表达式
-- 注意：1. having称为分组滤过条件,也就是说是分组需要的条件,所以必须与group by联用
--			  2. 通过having，聚合函数的计算结果也能当作条件来使用，解决了聚合函数无法放在where的问题
select SalesPerson,count(1) from SalesLT.Customer group by SalesPerson having count(1) >75

-------------------------------------------------------------------------------------------------------

-- 两个列中的值合并成一个列的值
-- select  列名1 + 列名2  from  表名
-- 注意：类型转换的问题，不相容的类型（int和nvarchar）需要类型转换才能合并
select LastName+Title from SalesLT.Customer

-- 不同类型之间的转换，两种方法
-- convert  (  目标类型  ,  需转换的列名  ,  格式规范  )
-- cast  (  需转换的列名  as  目标类型  )
select convert(nvarchar(30),CustomerID)+FirstName from SalesLT.Customer
select cast(CustomerID as nvarchar(32)) + FirstName from SalesLT.Customer

-------------------------------------------------------------------------------------------------------

-- 把另一个表的内容Copy过来，快速创建表的方式
-- select  列名  新的表名  from  旧的表名
select EmpId,EmpName into Employee3 from dbo.Employee where EmpId > 5

-------------------------------------------------------------------------------------------------------

-- 插入一行数据至某个表中
-- insert into  表名(列名1,列名2,列名3,....)  values(值1,值2,值3,....)：在指定表中增加新的一行数据
-- 如果插入数据的某个列的标识为：自动增长 的时候，我们可以用以下两种方法来防止报错

-->1. 不写拥有自动增长的列的列名
insert into Employee (EmpName,EmpGender,EmpAddress,EmpAge) values('2','3','4',5)

-->2. 把该表的identity_Insert打开
set identity_Insert Employee on -- 设置为启动
insert into Employee(EmpId,EmpName,EmpGender,EmpAddress,EmpAge) values(1,'2','3','4',5)
set identity_Insert Employee off -- 设置为关闭

-------------------------------------------------------------------------------------------------------

-- 把两个表的数据联合起来
-- select  列名  from  表名1
-- union all(不去重复)/union(去重复、效率低)
-- select  列名  from  表名2
select * from dbo.Employee
union all
select * from dbo.EmployeeNew

-------------------------------------------------------------------------------------------------------

-- 批量的向一个已存在的表中添加另一个表中的数据
-- insert  into  表1 (列名1,列名2，…)  select  列名1,列名2,……  from  表2
-- 当某个列的表示为自动增长的时候，需要开启identity_Insert，结束的时候关闭
set identity_Insert Employee on --设置为启动

insert into Employee(EmpId,EmpName,EmpAddress,EmpAge) 
select EmpId,EmpName,EmpAddress,EmpAge from dbo.EmployeeNew

insert into Employee(EmpId,EmpName,EmpAddress,EmpAge)
select 1,N'吴鹏',N'哈哈',10 union
select 2,N'嘘嘘',N'asd',20 union
select 3,'asd','sdff',40

set identity_Insert Employee off --设置为关闭

-------------------------------------------------------------------------------------------------------

-- 获取当前时间 getdate()
select getdate()

-- 在指定日期中，增加指定日期单位的时间
-- dateadd(  日期单位  ,  添加数量  ,  日期字符串  )
select dateadd(second,1,'2018-3-11')

-- 计算结束日期和开始日期的时间单位差
-- 结束日期 - 开始日期
-- 当结果为：0 的而时候，证明为本月/日/年…
-- datediff(  日期单位  ,  开始日期  ,  结束日期  )
select datediff(day,'2018-3-11','2018-2-5')

-- 获取一个日期字符串中，我们所指定日期单位的数量
-- datepart(  日期单位  ,  日期字符串)
select datepart(day,'2018-3-11')

-- 获取一个日期字符串的年/月/日…
-- 日期单位(  日期字符串  )
select year('2018-3-11')

-------------------------------------------------------------------------------------------------------

-- 指定 列/常量 变成大写/小写
-- upper/lower(  列名/常量  )
select upper('asdasd'),* from dbo.Employee
select lower('ASDAS'),* from dbo.Employee

-- 获取指定 列/常量 从 左边/右边 开始截取n个字符的数据
-- left/right(  列名/常量  ,  n个字符  )
select left(EmpName,2),* from dbo.Employee
select right(EmpName,2),* from dbo.Employee

-- 去掉指定 列/常量 的 左边/右边 的空格
-- Ltrim/Rtrim(  列名/常量  )
select Ltrim('                     qweqqweqwe                          ')

-------------------------------------------------------------------------------------------------------
-- join on
use damon

select 
	dbo.Customer.CustomerName,
	dbo.Product.ProductName,
	dbo.Product.ProductPrice 
from 
	dbo.Customer,
	dbo.Product 
where 
	dbo.Customer.CutomerID = dbo.Product.CustomerID

 use [damon]
select 
	dbo.Customer.CustomerName,
	dbo.Customer.CustomerAge,
	dbo.Product.ProductName,
	dbo.Product.ProductPrice 
from 
	dbo.Product 
left join 
	dbo.Customer
on 
	dbo.Product.CustomerID = dbo.Customer.CutomerID


use [AdventureWorksLT2008]

select SalesLT.SalesOrderHeader.SalesOrderNumber,SalesLT.Customer.FirstName from SalesLT.SalesOrderHeader join SalesLT.Customer on SalesLT.Customer.CustomerID = SalesLT.SalesOrderHeader.CustomerID

-------------------------------------------------------------------------------------------------------
-- 呼叫中心练习题
-- database：Test1
-- table：CallRecords

select * from dbo.CallRecords

----查询通话时间最长的5条记录
select top 5 datediff(second,StartDateTime,EndDateTime) as 时长 from dbo.CallRecords order by 时长 desc

----查询以0开头的通话总时,以秒为计算单位
select sum(datediff(second,StartDateTime,EndDateTime)) from dbo.CallRecords where TelNum like '0%'

----查询2010年7月通话总时长最多的前两个呼叫员的编号
select top 2 CallerNumber,sum(datediff(second,StartDateTime,EndDateTime)) as 通话总时长 from dbo.CallRecords where datepart(month,StartDateTime) = 7 group by CallerNumber order by 通话总时长 desc

----查询2010年7月拨打电话次数最多的前两个呼叫员的编号
select top 2 CallerNumber,Count(1) from dbo.CallRecords where datepart(month,StartDateTime) = 7 group by CallerNumber order by count(1) desc
